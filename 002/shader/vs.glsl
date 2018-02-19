#version 450
in vec3 pos;
out vec2 v_uv;

out vec4 v_pos;
uniform vec4 info;
uniform vec4 instance[512];
uniform mat4 view;
uniform mat4 proj;

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

void main() {
	v_uv = pos.xy;
	vec3 rpos = pos * 0.1;
	const float idmult = gl_InstanceID;
	const float width = 3.0;
	vec4 ipos = instance[gl_InstanceID] * 0.1;
	rpos.x +=  cos(ipos.y * idmult * 5.11112 * 0.01 - info.w) * 4.0; // ((noise(rpos.xyz * width + vec3(idmult))) * 2.0 - 1.0);
	rpos.y +=  sin(ipos.x * idmult * 7.11112 * 0.02 + info.w) * 3.0; // ((noise(rpos.yzx * width + vec3(idmult))) * 2.0 - 1.0);
	rpos.z += -cos(ipos.z * idmult * 9.11112 * 0.01) * 3.0; // ((noise(rpos.zxy * width + vec3(idmult))) * 2.0 - 1.0);
	v_pos = vec4(rpos, 1.0);
	gl_Position = proj * view * v_pos;
}
