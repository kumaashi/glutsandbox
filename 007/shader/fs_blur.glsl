#version 450

layout(binding=0) uniform sampler2D color_tex0;
uniform vec4 info;
uniform vec4 config;
in  vec2 v_uv;
out vec4 FragColor;

//https://github.com/Jam3/glsl-fast-gaussian-blur/blob/master/13.glsl
vec4 blur13(sampler2D image, vec2 uv, vec2 resolution, vec2 direction) {
	vec4 color = vec4(0.0);
	vec2 off1 = vec2(1.411764705882353) * direction;
	vec2 off2 = vec2(3.2941176470588234) * direction;
	vec2 off3 = vec2(5.176470588235294) * direction;
	color += texture2D(image, uv) * 0.1964825501511404;
	color += texture2D(image, uv + (off1 / resolution)) * 0.2969069646728344;
	color += texture2D(image, uv - (off1 / resolution)) * 0.2969069646728344;
	color += texture2D(image, uv + (off2 / resolution)) * 0.09447039785044732;
	color += texture2D(image, uv - (off2 / resolution)) * 0.09447039785044732;
	color += texture2D(image, uv + (off3 / resolution)) * 0.010381362401148057;
	color += texture2D(image, uv - (off3 / resolution)) * 0.010381362401148057;
	return color;
}

void main() {
	vec2 uv = v_uv * 0.5 + 0.5;
	FragColor = vec4(0.0);
	const float ssao_gain = 0.5;
	const float emit_gain = 1.5;
	const float shadow_gain = 1.00;
	if(config.w > 0.5) {
		FragColor.x = blur13(color_tex0, uv, info.xy, vec2(1, 0) * ssao_gain).x;
		FragColor.y = blur13(color_tex0, uv, info.xy, vec2(1, 0) * emit_gain).y;
		FragColor.z = blur13(color_tex0, uv, info.xy, vec2(1, 0) * shadow_gain).z;
	} else {
		FragColor.x = blur13(color_tex0, uv, info.xy, vec2(0, 1) * ssao_gain).x;
		FragColor.y = blur13(color_tex0, uv, info.xy, vec2(0, 1) * emit_gain).y;
		FragColor.z = blur13(color_tex0, uv, info.xy, vec2(0, 1) * shadow_gain).z;
	}
}

