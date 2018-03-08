#include <GL/freeglut.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int width = 1280;
int height = 720;
enum {
	SHADOW_MAP_WIDTH  = 4096 / 2,
	SHADOW_MAP_HEIGHT = 4096 / 2,
};


PFNGLACTIVETEXTUREPROC                  glActiveTexture             = NULL;
PFNGLATTACHSHADERPROC                   glAttachShader              = NULL;
PFNGLBEGINQUERYPROC                     glBeginQuery                = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC         glBeginTransformFeedback    = NULL;
PFNGLBINDATTRIBLOCATIONPROC             glBindAttribLocation        = NULL;
PFNGLBINDBUFFERBASEPROC                 glBindBufferBase            = NULL;
PFNGLBINDBUFFERPROC                     glBindBuffer                = NULL;
PFNGLBINDFRAMEBUFFERPROC                glBindFramebuffer           = NULL;
PFNGLBINDRENDERBUFFERPROC               glBindRenderBuffer          = NULL;
PFNGLBINDVERTEXARRAYPROC                glBindVertexArray           = NULL;
PFNGLBLITFRAMEBUFFERPROC                glBlitFramebuffer           = NULL;
PFNGLBUFFERDATAPROC                     glBufferData                = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC         glCheckFramebufferStatus    = NULL;
PFNGLCOMPILESHADERPROC                  glCompileShader             = NULL;
PFNGLCREATEPROGRAMPROC                  glCreateProgram             = NULL;
PFNGLCREATESHADERPROC                   glCreateShader              = NULL;
PFNGLDELETEBUFFERSPROC                  glDeleteBuffers             = NULL;
PFNGLDELETEFRAMEBUFFERSPROC             glDeleteFramebuffers        = NULL;
PFNGLDELETEPROGRAMPROC                  glDeleteProgram             = NULL;
PFNGLDELETEQUERIESPROC                  glDeleteQueries             = NULL;
PFNGLDELETERENDERBUFFERSPROC            glDeleteRenderbuffers       = NULL;
PFNGLDELETESHADERPROC                   glDeleteShader              = NULL;
PFNGLDELETEVERTEXARRAYSPROC             glDeleteVertexArrays        = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC       glDisableVertexAttribArray  = NULL;
PFNGLDISPATCHCOMPUTEPROC                glDispatchCompute           = NULL;
PFNGLDRAWBUFFERSPROC                    glDrawBuffers               = NULL;
PFNGLDRAWARRAYSINSTANCEDPROC            glDrawArraysInstanced       = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC        glEnableVertexAttribArray   = NULL;
PFNGLENDQUERYPROC                       glEndQuery                  = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC           glEndTransformFeedback      = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC        glFramebufferRenderbuffer   = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC           glFramebufferTexture2D      = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC             glFramebufferTexture        = NULL;
PFNGLGENBUFFERSPROC                     glGenBuffers                = NULL;
PFNGLGENERATEMIPMAPPROC                 glGenerateMipmap            = NULL;
PFNGLGENFRAMEBUFFERSPROC                glGenFramebuffers           = NULL;
PFNGLGENQUERIESPROC                     glGenQueries                = NULL;
PFNGLGENRENDERBUFFERSPROC               glGenRenderBuffers          = NULL;
PFNGLGENVERTEXARRAYSPROC                glGenVertexArrays           = NULL;
PFNGLGETATTRIBLOCATIONPROC              glGetAttribLocation         = NULL;
PFNGLGETBUFFERSUBDATAPROC               glGetBufferSubData          = NULL;
PFNGLGETPROGRAMINFOLOGPROC              glGetProgramInfoLog         = NULL;
PFNGLGETPROGRAMIVPROC                   glGetProgramiv              = NULL;
PFNGLGETQUERYOBJECTUIVPROC              glGetQueryObjectuiv         = NULL;
PFNGLGETSHADERINFOLOGPROC               glGetShaderInfoLog          = NULL;
PFNGLGETSHADERIVPROC                    glGetShaderiv               = NULL;
PFNGLGETUNIFORMLOCATIONPROC             glGetUniformLocation        = NULL;
PFNGLLINKPROGRAMPROC                    glLinkProgram               = NULL;
PFNGLMAPBUFFERPROC                      glMapBuffer                 = NULL;
PFNGLPROGRAMUNIFORM1IPROC               glProgramUniform1i          = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = NULL;
PFNGLRENDERBUFFERSTORAGEPROC            glRenderBufferStorage       = NULL;
PFNGLSHADERSOURCEPROC                   glShaderSource              = NULL;
PFNGLTEXIMAGE2DMULTISAMPLEPROC          glTexImage2DMultisample     = NULL;
PFNGLTEXIMAGE3DPROC                     glTexImage3D                = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC      glTransformFeedbackVaryings = NULL;
PFNGLUNIFORM1FPROC                      glUniform1f                 = NULL;
PFNGLUNIFORM1IPROC                      glUniform1i                 = NULL;
PFNGLUNIFORM4FVPROC                     glUniform4fv                = NULL;
PFNGLUNIFORMMATRIX4FVPROC               glUniformMatrix4fv          = NULL;
PFNGLUNIFORM1FVPROC                     glUniform1fv                = NULL;
PFNGLUNIFORM4IVPROC                     glUniform4iv                = NULL;
PFNGLUNIFORM1IVPROC                     glUniform1iv                = NULL;
PFNGLUNMAPBUFFERPROC                    glUnmapBuffer               = NULL;
PFNGLUSEPROGRAMPROC                     glUseProgram                = NULL;
PFNGLVERTEXATTRIBPOINTERPROC            glVertexAttribPointer       = NULL;
PFNGLVIEWPORTARRAYVPROC                 glViewportArrayv            = NULL;
PFNGLVIEWPORTINDEXEDFPROC               glViewportIndexedf          = NULL;
PFNGLVIEWPORTINDEXEDFVPROC              glViewportIndexedfv         = NULL;

void initFunc() {
	glActiveTexture                  = (PFNGLACTIVETEXTUREPROC             )wglGetProcAddress("glActiveTexture");
	glAttachShader                   = (PFNGLATTACHSHADERPROC              )wglGetProcAddress("glAttachShader");
	glBeginQuery                     = (PFNGLBEGINQUERYPROC                )wglGetProcAddress("glBeginQuery");
	glBeginTransformFeedback         = (PFNGLBEGINTRANSFORMFEEDBACKPROC    )wglGetProcAddress("glBeginTransformFeedback");
	glBindAttribLocation             = (PFNGLBINDATTRIBLOCATIONPROC        )wglGetProcAddress("glBindAttribLocation");
	glBindBuffer                     = (PFNGLBINDBUFFERPROC                )wglGetProcAddress("glBindBuffer");
	glBindBufferBase                 = (PFNGLBINDBUFFERBASEPROC            )wglGetProcAddress("glBindBufferBase");
	glBindFramebuffer                = (PFNGLBINDFRAMEBUFFERPROC           )wglGetProcAddress("glBindFramebuffer");
	glBindRenderBuffer               = (PFNGLBINDRENDERBUFFERPROC          )wglGetProcAddress("glBindRenderbuffer");
	glBindVertexArray                = (PFNGLBINDVERTEXARRAYPROC           )wglGetProcAddress("glBindVertexArray");
	glBlitFramebuffer                = (PFNGLBLITFRAMEBUFFERPROC           )wglGetProcAddress("glBlitFramebuffer");
	glBufferData                     = (PFNGLBUFFERDATAPROC                )wglGetProcAddress("glBufferData");
	glCheckFramebufferStatus         = (PFNGLCHECKFRAMEBUFFERSTATUSPROC    )wglGetProcAddress("glCheckFramebufferStatus");
	glCompileShader                  = (PFNGLCOMPILESHADERPROC             )wglGetProcAddress("glCompileShader");
	glCreateProgram                  = (PFNGLCREATEPROGRAMPROC             )wglGetProcAddress("glCreateProgram");
	glCreateShader                   = (PFNGLCREATESHADERPROC              )wglGetProcAddress("glCreateShader");
	glDeleteBuffers                  = (PFNGLDELETEBUFFERSPROC             )wglGetProcAddress("glDeleteBuffers");
	glDeleteFramebuffers             = (PFNGLDELETEFRAMEBUFFERSPROC        )wglGetProcAddress("glDeleteFramebuffers");
	glDeleteProgram                  = (PFNGLDELETEPROGRAMPROC             )wglGetProcAddress("glDeleteProgram");
	glDeleteQueries                  = (PFNGLDELETEQUERIESPROC             )wglGetProcAddress("glDeleteQueries");
	glDeleteRenderbuffers            = (PFNGLDELETERENDERBUFFERSPROC       )wglGetProcAddress("glDeleteRenderbuffers");
	glDeleteShader                   = (PFNGLDELETESHADERPROC              )wglGetProcAddress("glDeleteShader");
	glDeleteVertexArrays             = (PFNGLDELETEVERTEXARRAYSPROC        )wglGetProcAddress("glDeleteVertexArrays");
	glDisableVertexAttribArray       = (PFNGLDISABLEVERTEXATTRIBARRAYPROC  )wglGetProcAddress("glDisableVertexAttribArray");
	glDispatchCompute                = (PFNGLDISPATCHCOMPUTEPROC           )wglGetProcAddress("glDispatchCompute");
	glDrawBuffers                    = (PFNGLDRAWBUFFERSPROC               )wglGetProcAddress("glDrawBuffers");
	glDrawArraysInstanced            = (PFNGLDRAWARRAYSINSTANCEDPROC       )wglGetProcAddress("glDrawArraysInstanced");
	glEnableVertexAttribArray        = (PFNGLENABLEVERTEXATTRIBARRAYPROC   )wglGetProcAddress("glEnableVertexAttribArray");
	glEndQuery                       = (PFNGLENDQUERYPROC                  )wglGetProcAddress("glEndQuery");
	glEndTransformFeedback           = (PFNGLENDTRANSFORMFEEDBACKPROC      )wglGetProcAddress("glEndTransformFeedback");
	glFramebufferRenderbuffer        = (PFNGLFRAMEBUFFERRENDERBUFFERPROC   )wglGetProcAddress("glFramebufferRenderbuffer");
	glFramebufferTexture             = (PFNGLFRAMEBUFFERTEXTUREPROC        )wglGetProcAddress("glFramebufferTexture");
	glFramebufferTexture2D           = (PFNGLFRAMEBUFFERTEXTURE2DPROC      )wglGetProcAddress("glFramebufferTexture2D");
	glGenBuffers                     = (PFNGLGENBUFFERSPROC                )wglGetProcAddress("glGenBuffers");
	glGenFramebuffers                = (PFNGLGENFRAMEBUFFERSPROC           )wglGetProcAddress("glGenFramebuffers");
	glGenQueries                     = (PFNGLGENQUERIESPROC                )wglGetProcAddress("glGenQueries");
	glGenRenderBuffers               = (PFNGLGENRENDERBUFFERSPROC          )wglGetProcAddress("glGenRenderbuffers");
	glGenVertexArrays                = (PFNGLGENVERTEXARRAYSPROC           )wglGetProcAddress("glGenVertexArrays");
	glGenerateMipmap                 = (PFNGLGENERATEMIPMAPPROC            )wglGetProcAddress("glGenerateMipmap");
	glGetAttribLocation              = (PFNGLGETATTRIBLOCATIONPROC         )wglGetProcAddress("glGetAttribLocation");
	glGetBufferSubData               = (PFNGLGETBUFFERSUBDATAPROC          )wglGetProcAddress("glGetBufferSubData");
	glGetProgramInfoLog              = (PFNGLGETPROGRAMINFOLOGPROC         )wglGetProcAddress("glGetProgramInfoLog");
	glGetProgramiv                   = (PFNGLGETPROGRAMIVPROC              )wglGetProcAddress("glGetProgramiv");
	glGetQueryObjectuiv              = (PFNGLGETQUERYOBJECTUIVPROC         )wglGetProcAddress("glGetQueryObjectuiv");
	glGetShaderInfoLog               = (PFNGLGETSHADERINFOLOGPROC          )wglGetProcAddress("glGetShaderInfoLog");
	glGetShaderiv                    = (PFNGLGETSHADERIVPROC               )wglGetProcAddress("glGetShaderiv");
	glGetUniformLocation             = (PFNGLGETUNIFORMLOCATIONPROC        )wglGetProcAddress("glGetUniformLocation");
	glLinkProgram                    = (PFNGLLINKPROGRAMPROC               )wglGetProcAddress("glLinkProgram");
	glMapBuffer                      = (PFNGLMAPBUFFERPROC                 )wglGetProcAddress("glMapBuffer");
	glProgramUniform1i               = (PFNGLPROGRAMUNIFORM1IPROC          )wglGetProcAddress("glProgramUniform1i");
	glRenderBufferStorage            = (PFNGLRENDERBUFFERSTORAGEPROC       )wglGetProcAddress("glRenderbufferStorage");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	glShaderSource                   = (PFNGLSHADERSOURCEPROC              )wglGetProcAddress("glShaderSource");
	glTexImage2DMultisample          = (PFNGLTEXIMAGE2DMULTISAMPLEPROC     )wglGetProcAddress("glTexImage2DMultisample");
	glTexImage3D                     = (PFNGLTEXIMAGE3DPROC                )wglGetProcAddress("glTexImage3D");
	glTransformFeedbackVaryings      = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC )wglGetProcAddress("glTransformFeedbackVaryings");
	glUniform1f                      = (PFNGLUNIFORM1FPROC                 )wglGetProcAddress("glUniform1f");
	glUniform1i                      = (PFNGLUNIFORM1IPROC                 )wglGetProcAddress("glUniform1i");
	glUniform4fv                     = (PFNGLUNIFORM4FVPROC                )wglGetProcAddress("glUniform4fv");
	glUniformMatrix4fv               = (PFNGLUNIFORMMATRIX4FVPROC          )wglGetProcAddress("glUniformMatrix4fv");
	glUniform1fv                     = (PFNGLUNIFORM1FVPROC                )wglGetProcAddress("glUniform1fv");
	glUniform4iv                     = (PFNGLUNIFORM4IVPROC                )wglGetProcAddress("glUniform4iv");
	glUniform1iv                     = (PFNGLUNIFORM1IVPROC                )wglGetProcAddress("glUniform1iv");
	glUnmapBuffer                    = (PFNGLUNMAPBUFFERPROC               )wglGetProcAddress("glUnmapBuffer");
	glUseProgram                     = (PFNGLUSEPROGRAMPROC                )wglGetProcAddress("glUseProgram");
	glVertexAttribPointer            = (PFNGLVERTEXATTRIBPOINTERPROC       )wglGetProcAddress("glVertexAttribPointer");
	glViewportArrayv                 = (PFNGLVIEWPORTARRAYVPROC            )wglGetProcAddress("glViewportArrayv");
	glViewportIndexedf               = (PFNGLVIEWPORTINDEXEDFPROC          )wglGetProcAddress("glViewportIndexedf");
	glViewportIndexedfv              = (PFNGLVIEWPORTINDEXEDFVPROC         )wglGetProcAddress("glViewportIndexedfv");
	
	static GLuint VertexArrayID = 0;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	for(int i = 0 ; i < 8; i++) {
		glActiveTexture(GL_TEXTURE0 + i);
	}
	glUseProgram(0);
}

struct Float4 {
	union {
		float data[4];
		float raw[4];
	};
};

struct Float4x4 {
	union {
		float data[4][4];
		float raw[16];
	};
};

struct Int4 {
	union {
		int32_t data[4];
		int32_t raw[16];
	};
};

struct File {
	std::vector<char> buf;
	File(const char *name, const char *mode, bool zeropad = false) {
		if(name && mode) {
			auto fp = fopen(name, mode);
			if(fp) {
				fseek(fp, 0, SEEK_END);
				auto size = ftell(fp);
				fseek(fp, 0, SEEK_SET);
				buf.resize(size);
				memset(&buf[0], 0, buf.size());
				fread(buf.data(), 1, size, fp);
				fclose(fp);
				if(zeropad) {
					buf.push_back(0);
				}
			}
		}
	}

	int GetSize() {
		return buf.size();
	}

	char *GetData() {
		return buf.data();
	}
};

struct Shader {
	GLuint prog = 0;
	~Shader() {
		printf("%s : %016llX\n", __FUNCTION__, (uint64_t)this);
		if(prog) {
			glDeleteProgram(prog);
		}
	}
	void Begin() {
		glUseProgram(prog);
	}
	void End() {
		glUseProgram(0);
	}
	GLuint Get() {
		return prog;
	}

	int attachFunc(GLuint prog, GLenum type, const char *str, const char *name = NULL) {
		int result = -1;
		if(str) {
			GLuint shader = glCreateShader(type);
			glShaderSource(shader, 1, &str, 0);
			glCompileShader(shader);
			GLsizei buf_size = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH , &buf_size);
			if(buf_size > 1) {
				std::vector<char> vbuf;
				vbuf.resize(buf_size + 1); //null
				memset(&vbuf[0], 0, vbuf.size());
				glGetShaderInfoLog(shader, vbuf.size(), 0, &vbuf[0]);
				printf("[ERROR attachFunc=%s]\n%s", name, &vbuf[0]);
			} else {
				glAttachShader(prog, shader);
				result = 0;
			}
			glDeleteShader(shader);
		} else {
			printf("%s : name=%s is NULL!\n", __FUNCTION__, name);
		}
		return result;
	}

	Shader(const char *vsfile, const char *gsfile, const char *fsfile, const char *csfile = nullptr) {
		GLsizei buf_size = 0;
		GLuint ret = glCreateProgram();
		if(vsfile) {
			File fp(vsfile, "r", true);
			if(fp.GetSize()) {
				if(attachFunc(ret, GL_VERTEX_SHADER,   (const char *)fp.GetData(), (std::string("VertexShader   :") + vsfile).c_str())) {
					printf("GL_VERTEX_SHADER Compile\n");
				}
			} else {
				printf("%s : ERROR cant readfile=%s\n", __FUNCTION__, vsfile);
			}
		}
		if(gsfile) {
			File fp(gsfile, "r", true);
			if(fp.GetSize()) {
				if(attachFunc(ret, GL_GEOMETRY_SHADER, (const char *)fp.GetData(), (std::string("GeometryShader :") + gsfile).c_str())) {
					printf("GL_GEOMETRY_SHADER Compile\n");
				}
			} else {
				printf("%s : ERROR cant readfile=%s\n", __FUNCTION__, gsfile);
			}
		}
		if(fsfile) {
			File fp(fsfile, "r", true);
			if(fp.GetSize()) {
				if(attachFunc(ret, GL_FRAGMENT_SHADER, (const char *)fp.GetData(), (std::string("FragmentShader :") + fsfile).c_str())) {
					printf("GL_FRAGMENT_SHADER Compile\n");
				}
			} else {
				printf("%s : ERROR cant readfile=%s\n", __FUNCTION__, fsfile);
			}
		}
		if(csfile) {
			File fp(csfile, "r", true);
			if(fp.GetSize()) {
				if(attachFunc(ret, GL_COMPUTE_SHADER, (const char *)fp.GetData(), (std::string("ComputeShader :") + csfile).c_str())) {
					printf("GL_COMPUTE_SHADER Compile\n");
				}
			} else {
				printf("%s : ERROR cant readfile=%s\n", __FUNCTION__, csfile);
			}
		}
		glLinkProgram(ret);
		glGetProgramiv(ret, GL_INFO_LOG_LENGTH, &buf_size);
		if(buf_size > 1) {
			std::vector<char> vbuf;
			vbuf.resize(buf_size + 1);
			memset(&vbuf[0], 0, vbuf.size());
			glGetProgramInfoLog(ret, vbuf.size(), 0, &vbuf[0]);
			printf("[ERROR glGetProgramInfoLog]\n%s\n\n", &vbuf[0]);
			glDeleteProgram(ret);
			ret = 0;
		}
		prog = ret;
	}
};

struct Layout {
	std::vector<int> inputSizeTable;
	size_t formatSize = 0;
	~Layout() {
		printf("%s : %016llX\n", __FUNCTION__, (uint64_t)this);
	}
	Layout(std::vector<int> &table, size_t size) {
		inputSizeTable = table;
		formatSize = size;
		printf("%s : formatSize=%016llX\n", __FUNCTION__, formatSize);
	};
	
	void Set() {
		int64_t offset = 0;
		int64_t index = 0;
		for(auto & inputSize : inputSizeTable) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, inputSize, GL_FLOAT, GL_FALSE, formatSize, (GLvoid *)offset);
			offset += inputSize * sizeof(GLfloat);
			index++;
		}
	}
};

struct Buffer {
	GLuint id = 0;
	GLenum type = GL_ARRAY_BUFFER;
	~Buffer() {
		printf("%s : %016llX\n", __FUNCTION__, (uint64_t)this);
		glDeleteBuffers(1, &id);
	}
	Buffer(const void *buffer, size_t size, GLenum _type = GL_ARRAY_BUFFER) {
		type = _type;
		glGenBuffers(1, &id);
		glBindBuffer(type, id);
		glBufferData(type, size, buffer, type == GL_SHADER_STORAGE_BUFFER ? GL_DYNAMIC_COPY : GL_STATIC_DRAW);
		if(type == GL_SHADER_STORAGE_BUFFER) {
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, id);
		}
		glBindBuffer(type, 0);
	}
	GLuint Get() {
		return id;
	}
	void Begin() {
		glBindBuffer(type, id);
	}
	void End() {
		glBindBuffer(type, 0);
	}
	void DrawArrays(GLenum mode, GLuint count, GLuint instanceCount = 1) {
		glDrawArraysInstanced(mode, 0, count, instanceCount);
	}
};


struct Texture {
	GLuint id = 0;
	int width = 0;
	int height = 0;
	bool is_depth = false;
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	
	GLuint Get() {
		return id;
	}
	~Texture() {
		printf("%s : %016llX\n", __FUNCTION__, (uint64_t)this);
		glDeleteTextures(1, &id);
	}
	Texture(int w, int h, bool is_d = false) {
		width = w;
		height = h;
		is_depth = is_d;
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		if(is_depth) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		} else {
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, 0);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGBA, GL_FLOAT, 0);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
	void Bind(GLuint index, GLuint loc, bool create_mipmap = false, bool is_linear = false) {
		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(GL_TEXTURE_2D, id);
		auto filter_param = GL_NEAREST;
		auto filter_param_min = GL_LINEAR; //GL_NEAREST_MIPMAP_LINEAR;
		if(is_linear) {
			filter_param = GL_LINEAR;
			filter_param_min = GL_LINEAR; //GL_LINEAR_MIPMAP_LINEAR;
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_param);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_param_min);
		if(create_mipmap) {
			glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		glUniform1i(loc, index);
	}
};

struct RenderTarget {
	GLuint fbo = 0;
	std::vector<Texture *> color_textures;
	std::vector<Texture *> depth_textures;
	int width = 0, height = 0;
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	~RenderTarget() {
		for(auto &obj : color_textures) {
			delete obj;
		}
		for(auto &obj : depth_textures) {
			delete obj;
		}
		glDeleteFramebuffers(1, &fbo);
	}
	
	RenderTarget(int w, int h, int count) {
		glGenFramebuffers(1, &fbo);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		for(int i = 0; i < count; i++) {
			auto tex = new Texture(w, h, false);
			color_textures.push_back(tex);
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, tex->Get(), 0);
		}
		{
			auto tex = new Texture(w, h, true);
			depth_textures.push_back(tex);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, tex->Get(), 0);
		}
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		
		width = w;
		height = h;
	}
	
	void End() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void Begin() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		std::vector<GLuint> vid;
		for (int i = 0; i < color_textures.size(); i++) {
			vid.push_back(GL_COLOR_ATTACHMENT0 + i);
		}
		glDrawBuffers(vid.size(), vid.data());
		if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			printf("Unable FrameBuffer Status\n");
		}
	}
	
	void GetColorTexture(std::vector<Texture *> &vid) {
		for(auto &x : color_textures) {
			vid.push_back(x);
		}
	}

	void GetDepthTexture(std::vector<Texture *> &vid) {
		for(auto &x : depth_textures) {
			vid.push_back(x);
		}
	}
};


template<typename T>
struct UniformData {
	T *buf = nullptr;
	size_t count = 0;
	UniformData(T *src, size_t c) {
		buf = src;
		count = c;
	}
	size_t GetCount() {
		return count;
	}
	T *GetData() {
		return buf;
	}
};

using UniformFloat4Data = UniformData<Float4>;
using UniformFloat4x4Data = UniformData<Float4x4>;
using UniformInt4Data = UniformData<int32_t>;

struct Compute {
	std::vector<Shader *> shaders;
	std::vector<Buffer *> buffers;
	int width, height;
	Compute(int w, int h, size_t buffer_size) {
		width = w;
		height = h;
		ReloadShader();
		buffers.push_back(new Buffer(nullptr, buffer_size, GL_SHADER_STORAGE_BUFFER) ) ;
	}
	~Compute() {
		DeleteShader();
	}
	void DeleteShader() {
		for(auto &x : shaders) {
			delete x;
		}
		shaders.clear();
	}
	void ReloadShader() {
		DeleteShader();
		shaders.push_back(new Shader(nullptr, nullptr, nullptr, "shader/cs_vertexpos.glsl"));
	}
	void Dispatch(int index, GLuint x, GLuint y, GLuint z, float *vdata) {
		auto shader = shaders[index];
		if(shader) {
			shader->Begin();
			auto loc = glGetUniformLocation(shader->Get(), "info");
			glUniform4fv(loc, 1, (const GLfloat *)vdata);
			glDispatchCompute(x, y, z);
			//glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
			shader->End();
		}
	}
	void Bind(int index) {
		auto buffer = buffers[index];
		if(buffer) {
			buffer->Begin();
		}
	}
	void Unbind(int index = 0) {
	}
	
};


struct Screen {
	struct Info {
		int width, height;
		int rendertargetnumber;
		bool is_mipmap_create = false;
	};
	int width = 0;
	int height = 0;
	float frameTime = 0.0;
	float GetFrameTime() {
		return frameTime;
	}
	std::vector<RenderTarget *> rendertargets;
	std::vector<Buffer *> vertexbuffers;
	std::vector<Layout *> vertexlayouts;
	std::vector<Shader *> shaders;

	std::map<std::string, UniformFloat4Data *>   uniformmap_float4;
	std::map<std::string, UniformFloat4x4Data *> uniformmap_float4x4;
	std::map<std::string, UniformInt4Data *>     uniformmap_int4;

	struct VertexFormat {
		float position[3];
	};
	enum {
		PASS_SHADOW = 0,
		PASS_GBUFFER,
		PASS_SSAO,
		PASS_X_BLUR,
		PASS_Y_BLUR,
		PASS_PRESENT,
	};
	Screen(int w, int h) {
		width = w;
		height = h;
		std::vector<Screen::Info> vrendertargetnumber = {
			{
				SHADOW_MAP_WIDTH,
				SHADOW_MAP_HEIGHT, 0}, //depthpass
			{w / 1, h / 1, 3},         //G-Buffer //C0:ALBEDO,EMIT, C1:NOR,SPEC,  C2:WPOS,SPEC,
			{w / 1, h / 1, 1},         //SSAO     //R:AO,   G:SHADOW, B:xxxx, A:xxxx
			{w / 2, h / 2, 1},         //xblur    //R:AO,   G:SHADOW, B:EMIT, A:xxxx
			{w / 2, h / 2, 1},         //yblur    //R:AO,   G:SHADOW, B:EMIT, A:xxxx
			{w / 1, h / 1, 1},         //post     //R:PRESENT, G:PRESENT,   B:PRESENT, A:PRESENT
		};
		for(auto &info : vrendertargetnumber) {
			rendertargets.push_back(new RenderTarget(info.width, info.height, info.rendertargetnumber));
		}
		
		const std::vector<GLfloat> cube_vertex = {
			-1.0f,-1.0f,-1.0f, -1.0f,-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, //0
			1.0f, 1.0f,-1.0f,  -1.0f,-1.0f,-1.0f, -1.0f, 1.0f,-1.0f, //1
			1.0f,-1.0f, 1.0f, -1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,   //2
			1.0f, 1.0f,-1.0f, 1.0f,-1.0f,-1.0f, -1.0f,-1.0f,-1.0f,   //3
			-1.0f,-1.0f,-1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f,-1.0f, //4
			1.0f,-1.0f, 1.0f, -1.0f,-1.0f, 1.0f, -1.0f,-1.0f,-1.0f,  //5
			-1.0f, 1.0f, 1.0f, -1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f,  //6
			1.0f, 1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f,    //7
			1.0f,-1.0f,-1.0f, 1.0f, 1.0f, 1.0f, 1.0f,-1.0f, 1.0f,    //8
			1.0f, 1.0f, 1.0f, 1.0f, 1.0f,-1.0f, -1.0f, 1.0f,-1.0f,   //9
			1.0f, 1.0f, 1.0f, -1.0f, 1.0f,-1.0f, -1.0f, 1.0f, 1.0f,  //10
			1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,-1.0f, 1.0f    //11
		};
		std::vector<int> inputSizeTable = {3};
		for(int i = 0 ; i < vrendertargetnumber.size(); i++) {
			vertexbuffers.push_back(new Buffer(cube_vertex.data(), cube_vertex.size() * sizeof(GLfloat)));
			vertexlayouts.push_back(new Layout(inputSizeTable, sizeof(VertexFormat) ));
		}
		ReloadShader();
	}
	void DeleteShader() {
		for(auto &x : shaders) {
			delete x;
		}
		shaders.clear();
	}
	void ReloadShader() {
		DeleteShader();
		shaders.push_back(new Shader("shader/vs.glsl", "shader/gs.glsl", "shader/fs.glsl"));
		shaders.push_back(new Shader("shader/vs.glsl", "shader/gs.glsl", "shader/fs.glsl"));
		shaders.push_back(new Shader("shader/vs_present.glsl", nullptr, "shader/fs_genssx.glsl"));
		shaders.push_back(new Shader("shader/vs_present.glsl", nullptr, "shader/fs_blur.glsl"));
		shaders.push_back(new Shader("shader/vs_present.glsl", nullptr, "shader/fs_blur.glsl"));
		shaders.push_back(new Shader("shader/vs_present.glsl", nullptr, "shader/fs_present.glsl"));
	}
	
	void Draw(int index, int number, int instanceCount = 1) {
		auto buffer = vertexbuffers[index];
		if(buffer) {
			buffer->DrawArrays(GL_TRIANGLES, number, instanceCount);
		}
	}
	~Screen() {
		DeleteShader();
		for(auto &x : vertexlayouts) {
			delete x;
		}
		for(auto &x : vertexbuffers) {
			delete x;
		}
		for(auto &x : rendertargets) {
			delete x;
		}
	}

	RenderTarget *GetRenderTarget(int index) {
		return rendertargets[index];
	}
	Shader *GetShader(int index) {
		return shaders[index];
	}
	
	RenderTarget *Begin(int index, bool is_backbuffer = false) {
		auto rendertarget = rendertargets[index];
		auto shader = shaders[index];
		auto vertex = vertexbuffers[index];
		auto layout = vertexlayouts[index];
		if(rendertarget) rendertarget->Begin();
		if(is_backbuffer) {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
		if(shader) {
			shader->Begin();
		} else {
			printf("***********************************************************\n");
			printf(" Error Unbound Shader index=%d\n", index);
			printf("***********************************************************\n");
		}
		if(vertex) vertex->Begin();
		if(layout) layout->Set();
		
		Float4 vinfo = { float(width), float(height), 0, frameTime };
		UniformFloat4Data uinfo(&vinfo, 1);;
		SetUniform("info", &uinfo);
		
		for(auto &pair : uniformmap_float4) {
			auto & name = pair.first;
			auto & udata = pair.second;
			auto count = udata->GetCount();
			auto pdata = udata->GetData();
			auto loc = glGetUniformLocation(shader->Get(), name.c_str());
			glUniform4fv(loc, count, (const GLfloat *)pdata);
		}
		
		for(auto &pair : uniformmap_float4x4) {
			auto & name = pair.first;
			auto & udata = pair.second;
			auto count = udata->GetCount();
			auto pdata = udata->GetData();
			auto loc = glGetUniformLocation(shader->Get(), name.c_str());
			glUniformMatrix4fv(loc,  count, GL_FALSE, (const GLfloat *)pdata);
		}
		
		for(auto &pair : uniformmap_int4) {
			auto & name = pair.first;
			auto & udata = pair.second;
			auto count = udata->GetCount();
			auto pdata = udata->GetData();
			auto loc = glGetUniformLocation(shader->Get(), name.c_str());
			glUniform4iv(loc, count, pdata);
		}
		glScissor(0, 0, rendertarget->GetWidth(), rendertarget->GetHeight());
		glViewport(0, 0, rendertarget->GetWidth(), rendertarget->GetHeight());
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClearDepth(1.0);
		return rendertarget;
	}
	
	void End(int index) {
		if(index < vertexbuffers.size()) {
			auto vertex = vertexbuffers[index];
			if(vertex) vertex->End();
		}
		if(index < shaders.size()) {
			auto shader = shaders[index];
			if(shader) shader->End();
		}
		if(index < rendertargets.size()) {
			auto rt = rendertargets[index];
			if(rt) rt->End();
		}
	}
	void AdvanceFrame() {
		frameTime += 1.0f / 60.0f;
	}
	
	void SetUniform(std::string name, UniformFloat4Data *vdata) {
		uniformmap_float4[name] = vdata;
	}
	void SetUniform(std::string name, UniformFloat4x4Data *vdata) {
		uniformmap_float4x4[name] = vdata;
	}
	void SetUniform(std::string name, UniformInt4Data *vdata) {
		uniformmap_int4[name] = vdata;
	}
	int GetWidth() { return width; }
	int GetHeight() { return height; }
};
Screen *screen = nullptr;
Compute *compute = nullptr;

void releaseResource() {
	if(compute) delete compute;
	compute = nullptr;
	
	if(screen) delete screen;
	screen = nullptr;
	
}

void renderFrameFunc(void) {
	bool is_gen_mipmap = true;
	if(GetAsyncKeyState(VK_F5) & 0x0001) {
		compute->ReloadShader();
		screen->ReloadShader();
	}

	auto faspect = float(width) / float(height);
	auto fnear = 0.1f;
	auto ffar = 256.0f;
	static float angle  = 0.5f;
	static float y_light_offset = 0.0f;
	if(GetAsyncKeyState('H') & 0x8000) {
		angle += 0.025;
	}
	if(GetAsyncKeyState('L') & 0x8000) {
		angle -= 0.025;
	}
	if(GetAsyncKeyState('J') & 0x8000) {
		y_light_offset += 0.025;
	}
	if(GetAsyncKeyState('K') & 0x8000) {
		y_light_offset -= 0.025;
	}
	float cn = cos(angle);
	float sn = sin(angle);

	const float pos_delta = 0.05;
	static float pos_x = 0.0;
	static float pos_y = 5.0;
	static float pos_z = 5.0;
	if(GetAsyncKeyState('A') & 0x8000) pos_x -= pos_delta;
	if(GetAsyncKeyState('D') & 0x8000) pos_x += pos_delta;
	if(GetAsyncKeyState('W') & 0x8000) pos_z -= pos_delta;
	if(GetAsyncKeyState('S') & 0x8000) pos_z += pos_delta;
	if(GetAsyncKeyState('R') & 0x8000) pos_y += pos_delta;
	if(GetAsyncKeyState('F') & 0x8000) pos_y -= pos_delta;
	
	float light_x =  5 * cn;
	float light_y =  5 + y_light_offset;
	float light_z = -5 * sn;
	auto viewShadow = glm::lookAt(
				glm::vec3(light_x, light_y, light_z),
				glm::vec3(0, 0, 0),
				glm::vec3(0, 1, 0));
	auto eyepos = glm::vec3(pos_x, pos_y, pos_z);
	auto view = glm::lookAt(
				eyepos,
				glm::vec3(0, 0, 0),
				glm::vec3(0, 1, 0));
	
	//auto projShadow = glm::ortho<float>(-10,10,-10,10,fnear,ffar);
	auto projShadow = glm::ortho<float>(-10,10,-10,10,-10,20);
	auto proj = glm::perspective(glm::radians(90.0f), faspect, fnear, ffar);
	UniformFloat4x4Data ViewData((Float4x4 *)glm::value_ptr(view), 1);
	UniformFloat4x4Data ViewShadowData((Float4x4 *)glm::value_ptr(viewShadow), 1);
	UniformFloat4x4Data ProjData((Float4x4 *)glm::value_ptr(proj), 1);
	UniformFloat4x4Data ProjShadowData((Float4x4 *)glm::value_ptr(projShadow), 1);
	
	float vinfo[4] = {
		screen->GetFrameTime(),
		screen->GetFrameTime(),
		screen->GetFrameTime(),
		screen->GetFrameTime(),
	};
	compute->Dispatch(0, 32, 32, 1, vinfo);
	
	screen->SetUniform("view", &ViewData);
	screen->SetUniform("proj", &ProjData);
	screen->SetUniform("viewShadow", &ViewShadowData);
	screen->SetUniform("projShadow", &ProjShadowData);

	#define INSTANCE_MAX 512
	std::vector<Float4> vdata;
	for(int i = 0 ; i < INSTANCE_MAX; i++) {
		float findex = float(i);
		vdata.push_back({findex, findex, findex, findex});
	}
	UniformFloat4Data InstanceData((Float4 *)vdata.data(), vdata.size());
	screen->SetUniform("instance", &InstanceData);
	
	std::vector<Float4> vconfig;
	vconfig.push_back({1, 0, 0, 0});
	UniformFloat4Data ConfigData((Float4 *)vconfig.data(), vconfig.size());
	screen->SetUniform("config", &ConfigData);
	
	std::vector<Float4> veyepos;
	veyepos.push_back({eyepos.x, eyepos.y, eyepos.z, 0});
	UniformFloat4Data EyePosData((Float4 *)veyepos.data(), veyepos.size());
	screen->SetUniform("eyepos", &EyePosData);

	std::vector<Float4> vlightdir;
	vlightdir.push_back({light_x, light_y, light_z, 0});
	UniformFloat4Data LightDirData((Float4 *)vlightdir.data(), vlightdir.size());
	screen->SetUniform("lightdir", &LightDirData);
	
	std::vector<Float4> vlightcolor;
	vlightcolor.push_back({0.75f, 0.5f, 0.35f, 0});
	UniformFloat4Data LightColorData((Float4 *)vlightcolor.data(), vlightcolor.size());
	screen->SetUniform("lightcolor", &LightColorData);

	glEnable(GL_SCISSOR_TEST);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	
	//Screen::PASS_SHADOW
	glColorMask(false, false, false, false);
	{
		auto rt = screen->Begin(Screen::PASS_SHADOW);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		screen->Draw(0, 36, INSTANCE_MAX);
		screen->End(Screen::PASS_SHADOW);
	}

	vconfig[0].data[0] = 0;
	glColorMask(true, true, true, true);
	//Screen::PASS_GBUFFER
	{
		compute->Bind(0);
		auto rt = screen->Begin(Screen::PASS_GBUFFER);
		auto shader = screen->GetShader(Screen::PASS_GBUFFER);
		auto rendertarget = screen->GetRenderTarget(Screen::PASS_SHADOW);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		std::vector<Texture *> vdepthtex;
		rendertarget->GetDepthTexture(vdepthtex);
		auto name = std::string("depth_tex");
		for(auto &t : vdepthtex) {
			t->Bind(0, glGetUniformLocation(shader->Get(), name.c_str()), false, false);
		}
		screen->Draw(0, 36, INSTANCE_MAX);
		screen->End(Screen::PASS_GBUFFER);
	}

	glDisable(GL_DEPTH_TEST);

	//http://advances.realtimerendering.com/s2010/Ownby,Hall%20and%20Hall%20-%20Toystory3%20(SIGGRAPH%202010%20Advanced%20RealTime%20Rendering%20Course).pdf
	//Screen::PASS_SSAO
	{
		auto rt = screen->Begin(Screen::PASS_SSAO);
		auto shader = screen->GetShader(Screen::PASS_SSAO);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		auto rendertarget = screen->GetRenderTarget(Screen::PASS_GBUFFER);
		std::vector<Texture *> vcolortex;
		std::vector<Texture *> vdepthtex;
		rendertarget->GetColorTexture(vcolortex);
		rendertarget->GetDepthTexture(vdepthtex);
		int index = 0;
		for(auto &t : vcolortex) {
			auto name = std::string("color_tex") + std::to_string(index);
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()));
			index++;
		}
		for(auto &t : vdepthtex) {
			auto name = std::string("depth_tex");
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()));
			index++;
		}
		screen->Draw(0, 36);
		screen->End(Screen::PASS_SSAO);
	}

	//Screen::PASS_X_BLUR
	vconfig[0].data[3] = 0;
	{
		auto rt = screen->Begin(Screen::PASS_X_BLUR);
		auto shader = screen->GetShader(Screen::PASS_X_BLUR);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		auto rendertarget = screen->GetRenderTarget(Screen::PASS_SSAO);
		std::vector<Texture *> vcolortex;
		std::vector<Texture *> vcolortex_gbuffer;
		rendertarget->GetColorTexture(vcolortex);
		int index = 0;
		for(auto &t : vcolortex) {
			auto name = std::string("color_tex") + std::to_string(index);
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()), false, true);
			index++;
		}
		screen->Draw(0, 36);
		screen->End(Screen::PASS_X_BLUR);
	}

	//Screen::PASS_Y_BLUR
	vconfig[0].data[3] = 1;
	{
		glColorMask(true, true, true, true);
		auto rt = screen->Begin(Screen::PASS_Y_BLUR);
		auto shader = screen->GetShader(Screen::PASS_Y_BLUR);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		auto rendertarget = screen->GetRenderTarget(Screen::PASS_X_BLUR);
		std::vector<Texture *> vcolortex;
		std::vector<Texture *> vdepthtex;
		rendertarget->GetColorTexture(vcolortex);
		int index = 0;
		for(auto &t : vcolortex) {
			auto name = std::string("color_tex") + std::to_string(index);
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()), false, true);
			index++;
		}
		screen->Draw(0, 36);
		screen->End(Screen::PASS_Y_BLUR);
	}

	//Screen::PASS_PRESENT
	{
		screen->Begin(Screen::PASS_PRESENT, true);
		auto shader = screen->GetShader(Screen::PASS_PRESENT);
		glScissor(0, 0, width, height);
		glViewport(0, 0, width, height);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		auto rendertarget_gbuffer = screen->GetRenderTarget(Screen::PASS_GBUFFER);
		auto rendertarget_blur = screen->GetRenderTarget(Screen::PASS_Y_BLUR);
		std::vector<Texture *> vcolortex_gbuffer;
		std::vector<Texture *> vcolortex_blur;
		std::vector<Texture *> vdepthtex;
		rendertarget_gbuffer->GetColorTexture(vcolortex_gbuffer);
		rendertarget_blur->GetColorTexture(vcolortex_blur);
		rendertarget_gbuffer->GetDepthTexture(vdepthtex);
		int index = 0;
		for(auto &t : vcolortex_gbuffer) {
			auto name = std::string("color_tex_gbuffer") + std::to_string(index);
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()), false, false);
			index++;
		}
		for(auto &t : vcolortex_blur) {
			auto name = std::string("color_tex_blur") + std::to_string(index);
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()), true, true);
			index++;
		}
		for(auto &t : vdepthtex) {
			auto name = std::string("depth_tex");
			t->Bind(index, glGetUniformLocation(shader->Get(), name.c_str()), false, false);
			index++;
		}
		screen->Draw(0, 36);
		screen->End(Screen::PASS_PRESENT);
	}

	screen->AdvanceFrame();
	glutSwapBuffers();
	glutPostRedisplay();
}

void reshapeFunc(int w, int h) {
	printf("reshapeFunc\n");
	width = w;
	height = h;
	
	releaseResource();

	screen = new Screen(w, h);
	compute = new Compute(w, h, 32 * 32 * 4 * sizeof(float));
}

void exitFunc() {
	releaseResource();
}

void keyboardFunc(unsigned char key, int x, int y) {
	switch(key) {
	case 27: //ESC
		exit(0);
		break;
	}
}

void dumpInfo(void) {
	printf("Vendor: %s\n",   glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n",  glGetString(GL_VERSION));
	printf("GLSL: %s\n",     glGetString(GL_SHADING_LANGUAGE_VERSION));

	GLint value = 0;
	glGetIntegerv(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS        , &value);  printf("GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS        = %d\n",  value);
	glGetIntegerv(GL_MAX_SHADER_STORAGE_BLOCK_SIZE             , &value);  printf("GL_MAX_SHADER_STORAGE_BLOCK_SIZE             = %d\n",  value);
	glGetIntegerv(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS          , &value);  printf("GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS          = %d\n",  value);
	glGetIntegerv(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS        , &value);  printf("GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS        = %d\n",  value);
	glGetIntegerv(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS        , &value);  printf("GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS        = %d\n",  value);
	glGetIntegerv(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS    , &value);  printf("GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS    = %d\n",  value);
	glGetIntegerv(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS , &value);  printf("GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = %d\n",  value);
	glGetIntegerv(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS         , &value);  printf("GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS         = %d\n",  value);
	glGetIntegerv(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS        , &value);  printf("GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS        = %d\n",  value);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitContextVersion(4, 5);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitWindowSize(width, height); 
	glutCreateWindow(argv[0]);
	glutDisplayFunc(renderFrameFunc); 
	glutReshapeFunc(reshapeFunc);
	glutKeyboardFunc(keyboardFunc);
	dumpInfo();
	initFunc();
	atexit(exitFunc);
	glutMainLoop();
	return 0;
}

