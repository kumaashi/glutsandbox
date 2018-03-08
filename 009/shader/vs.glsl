#version 450

layout(std430, binding = 0) buffer layoutName
{
	vec4 data[];
};

in  vec3 pos;
out  vec2 v_uv;
out  vec4 v_pos;
out  vec4 v_shadow_pos;
flat out int v_id;

out  vec2 gs_uv;
out  vec4 gs_pos;
out  vec4 gs_instance_pos;
out  vec3 gs_dist_pos;
flat out int gs_id;

uniform vec4 info;
uniform vec4 config;
uniform vec4 instance[512];
uniform mat4 view;
uniform mat4 proj;
uniform mat4 viewShadow;
uniform mat4 projShadow;

void main_pass() {
	gs_uv = pos.xy;
	gs_pos = vec4(pos, 1.0);
	gs_id = gl_InstanceID;
	gs_instance_pos = instance[gl_InstanceID];
	gs_dist_pos = data[gl_InstanceID].xyz;
	gl_Position = gs_pos;
}

void main() {
	main_pass();
}
