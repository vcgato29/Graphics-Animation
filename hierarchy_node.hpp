#ifndef _HNODE_HPP_
#define _HNODE_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
// #include <fstream>

#include <vector>
#include <fstream>
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "gl_framework.hpp"

namespace csX75	 { 

	// A simple class that represents a node in the hierarchy tree
	class HNode {

		std::size_t vertex_buffer_size;
		std::size_t color_buffer_size;

		GLuint num_vertices;
		GLuint vao,vbo,texture;

		glm::mat4 rotation;
		glm::mat4 translation;
		
		std::vector<HNode*> children;
		HNode* parent;

		void update_matrices();

	  public:
		HNode (HNode*, GLuint, glm::vec4*,  glm::vec4*, glm::vec4*, glm::vec2*, int, int, int, int, GLuint);
		HNode (HNode*, GLuint, glm::vec4*,  glm::vec4*, glm::vec2*, int, int, int, GLuint);
		//HNode (HNode* , glm::vec4*,  glm::vec4*,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat);
		GLfloat tx,ty,tz,rx,ry,rz;
		void add_child(HNode*);
		void render();
		void change_parameters(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat);
		void render_tree();
		//Rotation
		void inc_rx();
		void inc_ry();
		void inc_rz();
		void dec_rx();
		void dec_ry();
		void dec_rz();
		//Translation
		void inc_tx();
		void inc_ty();
		void inc_tz();
		void dec_tx();
		void dec_ty();
		void dec_tz();
		void saveFrame(std::ofstream&);
		void loadFrame(std::ifstream&, std::vector<float>& );
		void setFrame(int&,std::vector<float>& );
	};

	glm::mat4* multiply_stack(std::vector <glm::mat4> );
};	

#endif