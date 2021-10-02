#include <vector>
#include <iostream>

template<class T>
using books = std::vector<T>;
template<typename T>
using point_down = std::shared_ptr<T>;

enum enum_go_brrrrr{ monkey, monkey_no_see, monkey_no_hear, monkey_no_speak};

int dice() { return std::rand(); }

bool coolKid() { return false; }

struct fork_knife { virtual void eyes() = 0; };
struct orange : fork_knife { virtual void eyes() { std::cout << "Orange" << std::endl; }; };
struct melon : fork_knife { virtual void eyes() { std::cout << "Melon" << std::endl; }; };
struct cherry : fork_knife { virtual void eyes() { std::cout << "Cherry" << std::endl; }; };
struct strawberry : fork_knife { virtual void eyes() { std::cout << "Strawberry" << std::endl; }; };
struct pineapple : fork_knife { virtual void eyes() { std::cout << "Pineapple" << std::endl; }; };
struct apple : fork_knife { virtual void eyes() { std::cout << "Apple" << std::endl; }; };

int main()
{
	if(coolKid() == false)
	{
		std::cout << "Poop" << std::endl;
	}
	books<point_down<fork_knife>> pancakes = { std::make_shared<orange>(), std::make_shared<melon>(), std::make_shared<cherry>(), std::make_shared<pineapple>(), std::make_shared<apple>() };

	for(auto green_apple: pancakes)
	{
		green_apple->eyes();
	}

	return dice();
}
