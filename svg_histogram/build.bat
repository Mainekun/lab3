g++ -c histogram.cpp histogram.hpp
g++ -c histogram_svg.cpp histogram_svg.hpp
g++ -o histosvg.exe histosvg.cpp histogram.o histogram_svg.o