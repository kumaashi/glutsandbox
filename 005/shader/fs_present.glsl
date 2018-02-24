#version 450

layout(binding=0) uniform sampler2D color_tex0;
layout(binding=1) uniform sampler2D color_tex1;
layout(binding=2) uniform sampler2D color_tex2;
layout(binding=3) uniform sampler2D color_tex3;
layout(binding=4) uniform sampler2D depth_tex ;

uniform vec4 info;

in  vec2 v_uv;
out vec4 FragColor;

float get_ao() {
	vec2 uv = v_uv * 0.5 + 0.5;
	vec3 samples[16];
	samples[0] = vec3(0.53812504, 0.18565957, -0.43192);
	samples[1] = vec3(0.13790712, 0.24864247, 0.44301823);
	samples[2] = vec3(0.33715037, 0.56794053, -0.005789503);
	samples[3] = vec3(-0.6999805, -0.04511441, -0.0019965635);
	samples[4] = vec3(0.06896307, -0.15983082, -0.85477847);
	samples[5] = vec3(0.056099437, 0.006954967, -0.1843352);
	samples[6] = vec3(-0.014653638, 0.14027752, 0.0762037);
	samples[7] = vec3(0.010019933, -0.1924225, -0.034443386);
	samples[8] = vec3(-0.35775623, -0.5301969, -0.43581226);
	samples[9] = vec3(-0.3169221, 0.106360726, 0.015860917);
	samples[10] = vec3(0.010350345, -0.58698344, 0.0046293875);
	samples[11] = vec3(-0.08972908, -0.49408212, 0.3287904);
	samples[12] = vec3(0.7119986, -0.0154690035, -0.09183723);
	samples[13] = vec3(-0.053382345, 0.059675813, -0.5411899);
	samples[14] = vec3(0.035267662, -0.063188605, 0.54602677);
	samples[15] = vec3(-0.47761092, 0.2847911, -0.0271716);
	float center_depth = texture(depth_tex , uv).r;
	float count = 0.0;
	float mipmap = 0.0;
	float total = 0.0;
	for(int k = 1; k <= 16; k++) {
		for(int i = 0; i < 16; i++) {
			vec2 duv = samples[i].xy / vec2(info.x / info.y, 1.0);
			vec2 ruv = uv + duv / (8.0 * float(k));
			float depth = texture(depth_tex , ruv).r;
			float diff = center_depth - depth;
			if(diff < 0.005 && diff > 0.0) {
				count = count + min(1.0 / 1.5, diff * 512.0);
			}
			total += 1.0;
		}
	}
	return clamp(1.0 - (count / total), 0.0, 1.0);
}


void main() {
	vec2 uv = v_uv * 0.5 + 0.5;
	FragColor = vec4(0.0);
	vec4 albedo = texture(color_tex0, uv);
	vec3 wNor  = texture(color_tex1, uv).xyz;
	vec3 wPos  = texture(color_tex2, uv).xyz;
	float cn = cos(0.5);
	float sn = sin(0.5);
	vec3 L = normalize(vec3(5.0 * cn, 5.0, -5.0 * sn));

	FragColor = albedo;
	FragColor *= max(0.2, dot(L, wNor));

	float ao = get_ao();
	ao = pow(ao, 16.0);
	FragColor *= vec4(ao);
	if(uv.x < 0.5 && uv.y > 0.5) {
		FragColor = vec4(ao);
	}
	
	if(false) {
		if(uv.x < 0.3333) {
			FragColor = vec4(wNor, 1.0);
		}
		if(uv.x > 0.66666) {
			FragColor = vec4( pow(texture(depth_tex , uv).r, 32.0) );
		}
	}
	
	FragColor.xyz *= vec3(1.0, 1.2, 2.5);
}

