#version 150

in  vec2 v_uv;
in vec4 v_pos;
out vec4 FragColor0;
out vec4 FragColor1;
out vec4 FragColor2;
out vec4 FragColor3;

void main() {
	FragColor0 = v_pos;
	FragColor1 = vec4(0,1,0,1);
	FragColor2 = vec4(0,1,1,1);
	FragColor3 = vec4(1,0,0,1);
}


 