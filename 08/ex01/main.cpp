#include "Span.hpp"

int main()
{
   try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
   } catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
   }
   std::cout << "----------" << std::endl;
   try {
        Span tmp = Span(5);
        std::vector<int> vec;
        for (int i = 0; i < 5; i++)
            vec.push_back(i * 2);
        tmp.addNumber(vec.begin(), vec.end());
        std::cout << tmp.shortestSpan() << std::endl;
		std::cout << tmp.longestSpan() << std::endl;
   } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
   }
   std::cout << "----------" << std::endl;
   {
        try {
            Span tmp = Span(RANGE);
            tmp.ft_add_many_numbers();
            std::cout << tmp.shortestSpan() << std::endl;
            std::cout << tmp.longestSpan() << std::endl;
        } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
        }
   }
	return 0;
}
