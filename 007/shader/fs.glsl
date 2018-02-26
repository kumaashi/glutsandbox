#version 150

uniform sampler2D depth_tex ;
uniform vec4 config ;
uniform vec4 info;
uniform vec4 eyepos;
uniform vec4 lightdir;
uniform mat4 view;
uniform mat4 proj;
in  vec2 v_uv;
in  vec4 v_pos;
in  vec4 v_shadow_pos;
in  vec3 v_nor;
in  float v_diff;
in  float v_spec;
flat in  int  v_id;
out vec4 FragColor0;
out vec4 FragColor1;
out vec4 FragColor2;
out vec4 FragColor3;

float noise(vec2 seed) {
    return fract(sin(dot(seed.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

void main() {
	FragColor0 = vec4(1.0);
	
	//shadow pass
	if(config.x > 0.5) {
		//no effect.
		FragColor0 = vec4(gl_FragCoord.z);
		return;
	}
	
	//GBuffer pass
	vec4 color0    = abs(v_pos) * 0.3;
	color0.x = noise(vec2(float(v_id * 3)));
	color0.y = noise(vec2(float(v_id * 5)));
	color0.z = noise(vec2(float(v_id * 7)));
	vec2 shadow_uv = v_shadow_pos.xy;
	float dens     = 4.0;
	float specMult = 1.0;
	if(v_id == 0) {
		specMult = 0.2;
		color0 = vec4(1.0 / 3.0);
	}

	//http://www.opengl-tutorial.org/jp/intermediate-tutorials/tutorial-16-shadow-mapping/
	vec2 poissonDisk[4] = vec2[](
		vec2( -0.94201624, -0.39906216 ),
		vec2( 0.94558609, -0.76890725 ),
		vec2( -0.094184101, -0.92938870 ),
		vec2( 0.34495938, 0.29387760 )
	);

	float mult = 0.2;
	float shadow_value = 1.0;
	for (int i = 0; i < 4 ; i++) {
		float shadow_depth = texture(depth_tex, shadow_uv + poissonDisk[i] / 1024.0).r;
		float vz = v_shadow_pos.z - 0.0025;
		float cz = shadow_depth;
		float diff_z = cz - vz;
		if(diff_z < 0.0) {
			shadow_value += 0.5;
		}
	}
	vec3  L      = normalize(lightdir.xyz);
	vec3  N      = normalize(v_nor);
	float D      = max(0.1, dot(N, L));
	
	vec3  V      = -normalize(v_pos.xyz);
	vec3  H      = normalize(L + V);
	float S      = pow(max(0.1, dot(N, H)), 16.0);
	
	FragColor0   = color0;
	FragColor0.w = 1.0 / shadow_value;
	FragColor1   = vec4(N, D);
	FragColor2   = vec4(v_pos.xyz, S);
}

