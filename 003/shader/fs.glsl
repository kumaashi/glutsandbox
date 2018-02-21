#version 150

uniform sampler2D depth_tex ;
uniform vec4 config ;
in  vec2 v_uv;
in  vec4 v_pos;
in  vec4 v_shadow_pos;
out vec4 FragColor0;
out vec4 FragColor1;
out vec4 FragColor2;
out vec4 FragColor3;

void main() {
	if(config.x < 0.5) {
		vec2 shadow_uv = v_shadow_pos.xy;
		FragColor0 = abs(v_pos) * 0.3;

		//http://www.opengl-tutorial.org/jp/intermediate-tutorials/tutorial-16-shadow-mapping/
		vec2 poissonDisk[4] = vec2[](
			vec2( -0.94201624, -0.39906216 ),
			vec2( 0.94558609, -0.76890725 ),
			vec2( -0.094184101, -0.92938870 ),
			vec2( 0.34495938, 0.29387760 )
		);
		float mult = 0.2;
		float shadow_value = 1.0;
		for (int i = 0; i < 4 ; i++){
			float shadow_depth = texture(depth_tex, shadow_uv + poissonDisk[i]/700.0).r;
			if(shadow_depth < v_shadow_pos.z - 0.005) {
				shadow_value += 1.0;
			}
		}
		FragColor0 *= 1.0 / shadow_value;
	} else {
		//no effect.
		FragColor0 = vec4(gl_FragCoord.z);
	}
}


 