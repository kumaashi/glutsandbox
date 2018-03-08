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
	
	//http://digitalrune.github.io/DigitalRune-Documentation/html/fa431d48-b457-4c70-a590-d44b0840ab1e.htm
	{
		vec2 kpos = gl_FragCoord.xy;
		int x_index = int(mod(kpos.x, 4.0));
		int y_index = int(mod(kpos.y, 4.0));
		vec4  mvalue = vec4(0.0);
		float rvalue = (0.0);
		if(x_index == 0) mvalue = vec4(1.0 / 17.0,  9.0 / 17.0,  3.0 / 17.0, 11.0 / 17.0); 
		if(x_index == 1) mvalue = vec4(13.0 / 17.0,  5.0 / 17.0, 15.0 / 17.0,  7.0 / 17.0);
		if(x_index == 2) mvalue = vec4(4.0 / 17.0, 12.0 / 17.0,  2.0 / 17.0, 10.0 / 17.0); 
		if(x_index == 3) mvalue = vec4(16.0 / 17.0,  8.0 / 17.0, 14.0 / 17.0,  6.0 / 17.0);
		if(y_index == 0) rvalue = mvalue.x;
		if(y_index == 1) rvalue = mvalue.y;
		if(y_index == 2) rvalue = mvalue.z;
		if(y_index == 3) rvalue = mvalue.w;
		float alpha = pow(length(v_pos.xyz - eyepos.xyz), 4.0);
		float value = alpha - rvalue;
		if(value < 0.0) {
			discard;
		}
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
	FragColor2   = vec4(v_pos.xyz, S * 5.0);
}

