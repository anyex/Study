

#ifndef _CUBE_H_
#define _CUBE_H_

class Cube {
public:
	int get_H();
	int get_W();
	int get_L();
	Cube(int w, int h, int l);
	void set_H(int h);
	void set_W(int w);
	void set_L(int L);

	int Area();//面积
	int Volume();//体积

	bool isEqual(Cube &cube);

private:
	int m_h;
	int m_w;
	int m_l;
};
#endif // 





// _CUBE_H_
