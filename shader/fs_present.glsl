#version 450

layout(binding = 0) uniform sampler2D color_tex_gbuffer0;
layout(binding = 1) uniform sampler2D color_tex_gbuffer1;
layout(binding = 2) uniform sampler2D color_tex_gbuffer2;
layout(binding = 3) uniform sampler2D color_tex_blur0   ;
layout(binding = 4) uniform sampler2D depth_tex   ;

uniform vec4 info;
uniform vec4 eyepos;
uniform vec4 lightdir;
uniform vec4 lightcolor;
uniform mat4 view;
uniform mat4 proj;
in      vec2 v_uv;
out     vec4 FragColor;


float GetDiffuse(vec2 uv) {
	return texture(color_tex_gbuffer1, uv).w;
}

float GetSpecular(vec2 uv) {
	return texture(color_tex_gbuffer2, uv).w;
}

float GetSSAO(vec2 uv) {
	float k = texture(color_tex_blur0, uv).x;
	return pow(k, 2.0);
}



vec3 GetColor(vec2 uv) {
	vec3  albedo      = texture(color_tex_gbuffer0, uv).xyz;
	float shadow      = texture(color_tex_gbuffer0, uv).w;
	float D           = GetDiffuse(uv);
	float S           = GetSpecular(uv);
	vec4  blur_color  = texture(color_tex_blur0, uv);
	float ssao        = pow(blur_color.x, 2.0);
	float emit        = blur_color.y;
	float blur_shadow = blur_color.z;
	vec3 color        = albedo * vec3(pow(ssao, 4.0)) * shadow * blur_shadow * D;
	color            += vec3(0.5, 1, 2) * S * 0.15;
	//color            += vec3(1, 0, 0) * emit * 5.15;
	float depth       = texture(depth_tex, uv).r;
	return color;
}

float noise(vec2 seed) {
    return fract(sin(dot(seed.xy, vec2(12.9898, 78.233))) * 43758.5453);
}


vec3 noise3d(vec3 p) {
	return normalize(vec3(noise(p.yz), noise(p.zx), noise(p.xy))) * 2.0 - 1.0;
}

vec3 get_ssr(vec3 N, vec3 wPos) {
	vec3 eyedir = wPos - eyepos.xyz;
	vec3 R = normalize(reflect(normalize(eyedir), normalize(N)));
	vec3 col = vec3(0.0);
	float dens = 1.0;
	float acc  = 0.03;
	vec3 start_pos = wPos + R * 0.001;
	for(int i = 1; i < 16; i++) {
		//vec3 p = wPos + acc * (R + noise3d(R * acc * N) * 0.12) * float(i);
		vec3 p = wPos + acc * R * float(i);
		vec4 kp = proj * view * vec4(p, 1.0);
		vec3 auv = (kp / kp.w).xyz * 0.5 + 0.5;
		float kdepth = texture(depth_tex, auv.xy).r;
		if(auv.z > kdepth) {
			const float thick = 0.001;
			const float diff = auv.z - kdepth;
			if( diff > thick ) {
				dens += 4.0;
			}
			col = mix(col, GetColor(auv.xy), 0.5);
		}
		dens += 1.5;
	}
	col /= dens;
	return col * 5.0;
}


void main() {
	vec2 uv = v_uv * 0.5 + 0.5;
	FragColor       = vec4(0.0);
	FragColor.xyz   = GetColor(uv);;
	vec3 N = texture(color_tex_gbuffer1, uv).xyz;
	vec3 world_pos  = texture(color_tex_gbuffer2, uv).xyz;
	FragColor.xyz  += get_ssr(N, world_pos);
	FragColor.w     = 1.0;
	return;
}

