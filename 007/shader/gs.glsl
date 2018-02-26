#version 410
#extension GL_EXT_geometry_shader4 : enable

in vec4 gs_pos[];
in vec4 gs_instance_pos[];
in vec3 gs_dist_pos[];
in vec2 gs_uv[];
in int gs_id[];

out      vec4 v_pos;
out      vec3 v_nor;
out      vec4 v_shadow_pos;
out      vec2 v_uv;
flat out int  v_id;

uniform vec4 info;
uniform vec4 config;
uniform vec4 lightdir;
uniform mat4 view;
uniform mat4 proj;
uniform mat4 viewShadow;
uniform mat4 projShadow;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

vec2 rot(vec2 p, float a) {
	float c = cos(a);
	float s = sin(a);
	return vec2(
		p.x * c - p.y * s,
		p.x * s + p.y * c);
}

vec3 getVertexPos(int index) {
	vec3 pos    = gs_pos[index].xyz;
	vec3 ipos   = gs_dist_pos[index];
	float rotate_key = ipos.x + ipos.y + ipos.z;
	vec3 rpos   = pos * 0.2;
	rpos.xy     = rot(rpos.xy, rotate_key);
	rpos.yz     = rot(rpos.yz, rotate_key);
	return rpos;
}

void procVertex(int index, vec3 rpos, vec3 N) {
	v_uv        = gs_uv[index];
	v_id        = gs_id[index];
	v_pos       = vec4(rpos, 1.0);
	v_nor       = N;

	if(v_id == 0) {
		vec3 p = gs_pos[index].xyz;
		p.y  *= 0.1;
		p.xz *= 10.0;
		p.y  -= 3.0;
		v_pos = vec4(p, 1.0);
		v_nor = vec3(0, 1, 0);
	}

	v_shadow_pos = vec4(0.0);
	if(config.x < 0.5) {
		gl_Position = proj * view * v_pos;
		mat4 biasMatrix;
		biasMatrix[0] = vec4(0.5, 0.0, 0.0, 0.0);
		biasMatrix[1] = vec4(0.0, 0.5, 0.0, 0.0);
		biasMatrix[2] = vec4(0.0, 0.0, 0.5, 0.0);
		biasMatrix[3] = vec4(0.5, 0.5, 0.5, 1.0);
		v_shadow_pos = biasMatrix * projShadow * viewShadow * v_pos;
	} else {
		gl_Position = projShadow * viewShadow * v_pos;
	}
}

void main() {
	vec3 rpos[3];
	for(int i = 0; i < 3; i++) {
		rpos[i] = getVertexPos(i);
	}
	vec3 N = normalize(cross(rpos[2].xyz - rpos[1].xyz, rpos[0].xyz - rpos[2].xyz));
	for(int i = 0; i < 3; i++) {
		procVertex(i, rpos[i] + gs_dist_pos[i], N); //normalize(rpos[i]));
		EmitVertex();
	}
	EndPrimitive();
}
