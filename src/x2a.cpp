#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void ModifyFile(std::string& file_path)
{
	if (file_path.find('\"') != std::string::npos)
	{
		file_path = file_path.substr(1, file_path.length() - 2);
	}

	std::ifstream file(file_path);
	if (file.is_open())
	{
		std::stringstream lines;
		std::string line;
		unsigned int modified_count = 0;

		while (std::getline(file, line))
		{
			size_t position = line.find('X');

			if (position != std::string::npos)
			{
				line = line.substr(0, position) + 'A' + line.substr(position + 1);
				modified_count++;
			}
			lines << line << '\n';
		}
		file.close();
		
		printf("Um total de %d linhas serão alteradas.\n", modified_count);
		printf("Deseja prosseguir? (S/n): ");
		std::string answer;
		std::getline(std::cin, answer);
		if (answer.find('N') == std::string::npos || answer.find('n') == std::string::npos)
		{
			std::ofstream file_out(file_path);
			file_out << lines.str();
			file_out.close();
		}
		
	}
	else
	{
		std::cout << "N�o foi possivel abrir o arquivo \n";
		std::cin.get();
	}
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Digite o caminho para o arquivo: \n";

		std::string file_path;
		std::getline(std::cin, file_path);

		ModifyFile(file_path);
		return 0;
	}

	std::string file_path = argv[1];
	ModifyFile(file_path);

	return 0;
}