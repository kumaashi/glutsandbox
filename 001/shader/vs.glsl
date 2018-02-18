#version 450
in vec3 pos;
out vec2 v_uv;

out vec4 v_pos;
uniform mat4 view;
uniform mat4 proj;
void main() {
	v_uv = pos.xy;
	v_pos = vec4(pos, 1.0);
	gl_Position = proj * view * v_pos;
}
