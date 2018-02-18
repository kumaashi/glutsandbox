#version 450
in   vec3 pos;
out  vec2 v_uv;
void main() {
	v_uv = pos.xy;
	gl_Position = vec4(pos, 1.0);
}
