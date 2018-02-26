#version 450
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

float mod289(float x){return x - floor(x * (1.0 / 289.0)) * 289.0;}
vec4 mod289(vec4 x){return x - floor(x * (1.0 / 289.0)) * 289.0;}
vec4 perm(vec4 x){return mod289(((x * 34.0) + 1.0) * x);}

float noise(vec3 p){
    vec3 a = floor(p);
    vec3 d = p - a;
    d = d * d * (3.0 - 2.0 * d);

    vec4 b = a.xxyy + vec4(0.0, 1.0, 0.0, 1.0);
    vec4 k1 = perm(b.xyxy);
    vec4 k2 = perm(k1.xyxy + b.zzww);

    vec4 c = k2 + a.zzzz;
    vec4 k3 = perm(c);
    vec4 k4 = perm(c + 1.0);

    vec4 o1 = fract(k3 * (1.0 / 41.0));
    vec4 o2 = fract(k4 * (1.0 / 41.0));

    vec4 o3 = o2 * d.z + o1 * (1.0 - d.z);
    vec2 o4 = o3.yw * d.x + o3.xz * (1.0 - d.x);

    return o4.y * d.y + o4.x * (1.0 - d.y);
}

vec3 get_dist_pos(int id) {
	const float width = 3.0;
	const float idmult = id;
	vec4 ipos = instance[id] * 0.1;
	float x =  cos(ipos.y * idmult * 5.11112 * 0.01 + info.w * 0.31) * 4.0; // ((noise(rpos.xyz * width + vec3(idmult))) * 2.0 - 1.0);
	float y =  sin(ipos.x * idmult * 7.11112 * 0.02 + info.w * 0.32) * 3.0; // ((noise(rpos.yzx * width + vec3(idmult))) * 2.0 - 1.0);
	float z = -cos(ipos.z * idmult * 9.11112 * 0.01 + info.w * 0.33) * 3.0; // ((noise(rpos.zxy * width + vec3(idmult))) * 2.0 - 1.0);
	return vec3(x, y, z);
}

void main_pass() {
	gs_uv = pos.xy;
	gs_pos = vec4(pos, 1.0);
	gs_id = gl_InstanceID;
	gs_instance_pos = instance[gl_InstanceID];
	gs_dist_pos = get_dist_pos(gs_id);
	gl_Position = gs_pos;
}

void main() {
	main_pass();
}
