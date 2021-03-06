#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <unordered_map>

#include "vendor/glm/glm.hpp"

struct	ShaderSource
{
	std::string	vertexSource {};
	std::string	fragmentSource {};
};

class	Shader
{
private:
	std::string								file_path;
	unsigned int							m_renderer_id;
	std::unordered_map<std::string, int>	m_uniform_location_cache;

public:
	Shader(const std::string &file_path);
	~Shader();

	void	bind() const;
	void	unbind() const;

	void	set_uniform_1i(const std::string &name, int value);
	void	set_uniform_4f(const std::string &name, float f0, float f1, float f2, float f3);
	void	set_uniform_matrix_4f(const std::string &name, const glm::mat4 &matrix);

private:
	ShaderSource	retrieve_shader(const std::string &file_path);
	unsigned int	compile_shader(unsigned int type, const std::string &source);
	unsigned int	create_shader(const std::string &vertex_shader, const std::string &fragment_shader);
	int				get_uniform_location(const std::string &name);
};

#endif
