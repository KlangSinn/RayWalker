#include <iostream>
#include <thread>

#include <glutwindow.hpp>

class Renderer {
public :

  void render() {
    // GET GLUTWINDOW INSTANCE
    glutwindow& window = glutwindow::instance();
    
    for (int y = 0; y < window.height(); ++y) {
      for (int x = 0; x < window.width(); ++x) {
        Pixel p(x, y);
        p.color = Color(0.0, 1.0, float(x)/window.height());

		// DRAW IN GLUTWINDOW
        window.write(p); 
      }
    }
  }
};

int main(int argc, char* argv[]) {
	std::cout << "Hello, I am RayWalker." << std::endl;

	// WINDOW RESOLUTION
	const int width = 640;
	const int height = 320;

	// CREATE OUTPUT WINDOW
	glutwindow::init(width, height, 100, 100, "RayWalker", argc, argv);
	Renderer rendi;
	std::thread thr(std::bind(&Renderer::render, &rendi));
	glutwindow::instance().run();

	return 0;
}