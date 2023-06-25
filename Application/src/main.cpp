
#include "win.h"

#include "../../Engine/include/engine.h"
#include "render.h"

int main()
{
	Win w(640, 480, "Virtualization");
	auto window = w.getWin();

	Engine e;
	Render render;
	float r = 0.0f, g = 0.5f, b = 0.0f, a = 1.0f;

	while (w.status)
	{
		r > 1.0f ? r = 0 : r += 0.01f;
		g > 1.0f ? g = 0 : g += 0.01f;
		b > 1.0f ? b = 0 : b += 0.01f;

		std::cout << r << g << b << a << "\n";

		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		w.swapBuffer();
	}

	return 0;
}