#include <iostream>
#include <chrono>
#include <ctime>

int main() {

	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
	//2d array
	{
		const int width = 250;
		const int height = 250;
		int array2d[width*height];

		start = std::chrono::system_clock::now();
		//optimized for cache
		for (int i = 0; i < 1000; i++)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					array2d[y*width + x] += x;
				}
			}
		}

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Elapsed time optimized for cache 2d array: " << elapsed_seconds.count() << "s\n";


		start = std::chrono::system_clock::now();
		//not optimized for cache
		for (int i = 0; i < 1000; i++)
		{
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					array2d[y*width + x] += x;
				}
			}
		}

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Elapsed time not optimized for cache 2d array: " << elapsed_seconds.count() << "s\n";

	}
	//3d array
	{
		const int width = 50;
		const int height = 50;
		const int depth = 50;
		int array3d[width*height*depth];
		start = std::chrono::system_clock::now();
		//optimized for cache
		for (int i = 0; i < 1000; i++)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					for (int z = 0; z < depth; z++)
					{
						array3d[y*height*width + x * width + z] += z;
					}
				}
			}
		}

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Elapsed time optimized for cache 3d array: " << elapsed_seconds.count() << "s\n";

		start = std::chrono::system_clock::now();
		//not optimized for cache
		for (int i = 0; i < 1000; i++)
		{
			
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					for (int z = 0; z < depth; z++)
					{
						array3d[y*height*width + x * width + z] += z;
					}
				}
			}
		}

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Elapsed time not optimized for cache 3d array: " << elapsed_seconds.count() << "s\n";

		start = std::chrono::system_clock::now();
		//not optimized for cache
		for (int i = 0; i < 1000; i++)
		{

			
			for (int z = 0; z < depth; z++)
			{
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						array3d[y*height*width + x * width + z] += z;
					}
				}
			}
		}

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Elapsed time not optimized for cache 3d array: " << elapsed_seconds.count() << "s\n";

	}
	
	return 0;
}