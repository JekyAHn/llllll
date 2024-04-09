#include <iostream>

int main()
{
	int num = 0;
	std::string name;

	std::cout << "백호영 : 아힘들다..." << std::endl;

	while (num != 18)
	{
		std::cout << "나쁜놈의 이름과 나이를 입력하세요" << std::endl;
		std::cin >> name >> num;

	}
	
	std::cout << "백호영 : 수정누나보다 " << num << "살이나 어린주제에" << name << " 나쁜자식"<< std::endl;
	
	
	return 0;
}