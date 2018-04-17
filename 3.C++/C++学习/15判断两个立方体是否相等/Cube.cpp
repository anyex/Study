#include "cube.h"


int Cube::get_H()
{
	return m_h;
}

int Cube::get_W()
{
	return m_w;
}

int Cube::get_L()
{
	return m_l;
}

Cube::Cube(int w, int h, int l)
{
	m_h = h;
	m_w = w;
	m_l = l;
}
void Cube::set_H(int h)
{
	m_h = h;
}
void Cube::set_W(int w)
{
	m_w = w;
}
void Cube::set_L(int L)
{
	m_l = L;
}

int Cube::Area()
{      
	 
	   
		return 2 * ((m_w*m_h) + (m_w*m_l) + (m_l*m_h));
}
//Με»ύ

int Cube::Volume()
{
	return m_l*m_h*m_w;
}
bool Cube::isEqual(Cube &cube)
{
	bool ret = (m_h == cube.m_h) && (m_w == cube.m_w) && (m_l == cube.m_l);

	return ret;
}