#include <GL/freeglut.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

int width = 800;
int height = 600;

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
	glDisableVertexAttribArray       = (PFNGLDISABLEVERTEXATTRIBARRAYPROC  )wglGetProcAddress("glDisableVertexAttribArray");;
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
	glUnmapBuffer                    = (PFNGLUNMAPBUFFERPROC               )wglGetProcAddress("glUnmapBuffer");
	glUseProgram                     = (PFNGLUSEPROGRAMPROC                )wglGetProcAddress("glUseProgram");
	glVertexAttribPointer            = (PFNGLVERTEXATTRIBPOINTERPROC       )wglGetProcAddress("glVertexAttribPointer");
	glViewportArrayv                 = (PFNGLVIEWPORTARRAYVPROC            )wglGetProcAddress("glViewportArrayv");
	glViewportIndexedf               = (PFNGLVIEWPORTINDEXEDFPROC          )wglGetProcAddress("glViewportIndexedf");
	glViewportIndexedfv              = (PFNGLVIEWPORTINDEXEDFVPROC         )wglGetProcAddress("glViewportIndexedfv");
}


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
	GLuint GetProgram() {
		return prog;
	}
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
	Shader(const char *vsfile, const char *gsfile, const char *fsfile) {
		auto attachFunc = [&](GLuint prog, GLenum type, const char *str, const char *name = NULL) {
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
				}
				glDeleteShader(shader);
			} else {
				printf("%s : name=%s is NULL!\n", __FUNCTION__, name);
			}
		};

		GLsizei buf_size = 0;
		GLuint ret = glCreateProgram();
		if(vsfile) {
			printf("GL_VERTEX_SHADER Compile\n");
			File fp(vsfile, "r", true);
			attachFunc(ret, GL_VERTEX_SHADER,   (const char *)fp.GetData(), (std::string("VertexShader   :") + vsfile).c_str());
		}
		if(gsfile) {
			printf("GL_GEOMETRY_SHADER Compile\n");
			File fp(gsfile, "r", true);
			attachFunc(ret, GL_GEOMETRY_SHADER, (const char *)fp.GetData(), (std::string("GeometryShader :") + gsfile).c_str());
		}
		if(fsfile) {
			printf("GL_FRAGMENT_SHADER Compile\n");
			File fp(fsfile, "r", true);
			attachFunc(ret, GL_FRAGMENT_SHADER, (const char *)fp.GetData(), (std::string("FragmentShader :") + fsfile).c_str());
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
	~Buffer() {
		printf("%s : %016llX\n", __FUNCTION__, (uint64_t)this);
		glDeleteBuffers(1, &id);
	}
	Buffer(const void *buffer, size_t size) {
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	GLuint Get() {
		return id;
	}
	void Begin() {
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}
	void End() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void DrawArrays(GLenum mode, GLuint count) {
		glDrawArrays(mode, 0, count); // GL_TRIANGLES
	}
};


struct Texture {
	GLuint id = 0;
	int width = 0;
	int height = 0;
	bool is_depth = false;
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
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		} else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, 0);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
	void Bind(GLuint index, GLuint loc) {
		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(GL_TEXTURE_2D, id);
		glUniform1i(loc, index);
	}
};

struct RenderTarget {
	GLuint fbo = 0;
	std::vector<Texture *> color_textures;
	std::vector<Texture *> depth_textures;

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

struct Screen {
	int width = 0;
	int height = 0;
	std::vector<RenderTarget *> rendertargets;
	std::vector<Buffer *> vertexbuffers;
	std::vector<Layout *> vertexlayouts;
	std::vector<Shader *> shaders;
	struct VertexFormat {
		float position[3];
	};
	
	Screen(int w, int h, std::vector<int> &vrendertargetnumber) {
		width = w;
		height = h;
		for(auto &number : vrendertargetnumber) {
			rendertargets.push_back(new RenderTarget(w, h, number));
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
		vertexbuffers.push_back(new Buffer(cube_vertex.data(), cube_vertex.size() * sizeof(GLfloat)));
		vertexbuffers.push_back(new Buffer(cube_vertex.data(), cube_vertex.size() * sizeof(GLfloat)));
		vertexlayouts.push_back(new Layout(inputSizeTable, sizeof(VertexFormat) ));
		vertexlayouts.push_back(new Layout(inputSizeTable, sizeof(VertexFormat) ));
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
		shaders.push_back(new Shader("shader/vs.glsl", nullptr, "shader/fs.glsl"));
		shaders.push_back(new Shader("shader/vs.glsl", nullptr, "shader/fs_present.glsl"));
	}
	
	void Draw(int index, int number) {
		auto buffer = vertexbuffers[index];
		if(buffer) {
			buffer->DrawArrays(GL_TRIANGLES, number);
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
	void Begin(int index, bool is_backbuffer = false) {
		auto rendertarget = rendertargets[index];
		auto shader = shaders[index];
		auto vertex = vertexbuffers[index];
		auto layout = vertexlayouts[index];
		if(rendertarget) rendertarget->Begin();
		if(is_backbuffer) {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
		if(shader) shader->Begin();
		if(vertex) vertex->Begin();
		if(layout) layout->Set();
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
	int GetWidth() { return width; }
	int GetHeight() { return height; }
};
Screen *screen = nullptr;

void releaseResource() {
	if(screen) delete screen;
	screen = nullptr;
}

void renderFrameFunc(void) {
	if(GetAsyncKeyState(VK_F5) & 0x0001) {
		screen->ReloadShader();
	}
	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	
	screen->Begin(0);
	glScissor(0, 0, width, height);
	glViewport(0, 0, width, height);
	glClearColor(0, 0.4, 0.7, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	screen->Draw(0, 12);
	screen->End(0);
	
	screen->Begin(1, true);
	glScissor(0, 0, width, height);
	glViewport(0, 0, width, height);
	glClearColor(0, 2.4, 0.7, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		auto rendertarget = screen->GetRenderTarget(0);
		std::vector<Texture *> vcolortex;
		std::vector<Texture *> vdepthtex;
		rendertarget->GetColorTexture(vcolortex);
		rendertarget->GetDepthTexture(vdepthtex);
		int index = 0;
		auto shader = screen->GetShader(1);
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
	}
	screen->Draw(0, 12);
	screen->End(1);
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void reshapeFunc(int w, int h) {
	printf("reshapeFunc\n");
	width = w;
	height = h;
	
	releaseResource();
	std::vector<int> vrendertargetnumber = {
		4,
		1,
	};
	screen = new Screen(w, h, vrendertargetnumber);
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
	
	static GLuint VertexArrayID = 0;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	for(int i = 0 ; i < 8; i++) {
		glActiveTexture(GL_TEXTURE0 + i);
	}
	glUseProgram(0);
	
	atexit(exitFunc);
	glutMainLoop();
	return 0;
}

