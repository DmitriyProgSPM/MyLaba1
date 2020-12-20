#include <iostream>
#include <cmath>

void printMatrix(const int * const * matrix, const int matrixSize) {
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < matrixSize; ++j) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

void spiralFill(int **& matrix, const int matrixSize) {
	int currentRowStart = 0, currentColumnStart = 0;
	int currentRowEnd = matrixSize, currentColumnEnd = matrixSize;
	while (currentRowStart < currentRowEnd && currentColumnStart < currentColumnEnd) {
		for (int i = currentColumnStart; i < currentColumnEnd; ++i) {
			matrix[currentRowStart][i] = std::rand() % (matrixSize * matrixSize);
			std::cout << "Added element with indexes [" << currentRowStart << ";" << i << "]" << std::endl;
			printMatrix(matrix, matrixSize);
		}
		currentRowStart++;

		for (int i = currentRowStart; i < currentRowEnd; ++i) {
			matrix[i][currentColumnEnd - 1] = std::rand() % (matrixSize * matrixSize);
			std::cout << "Added element with indexes [" << i << ";" << currentColumnEnd - 1 << "]" << std::endl;
			printMatrix(matrix, matrixSize);
		}
		currentColumnEnd--;

		if (currentRowStart < currentRowEnd) {
			for (int i = currentColumnEnd - 1; i >= currentColumnStart; --i) {
				matrix[currentRowEnd - 1][i] = std::rand() % (matrixSize * matrixSize);
				std::cout << "Added element with indexes [" << currentRowEnd - 1 << ";" << i << "]" << std::endl;
				printMatrix(matrix, matrixSize);
			}
			currentRowEnd--;
		}

		if (currentColumnStart < currentColumnEnd) {
			for (int i = currentRowEnd - 1; i >= currentRowStart; --i) {
				matrix[i][currentColumnStart] = std::rand() % (matrixSize * matrixSize);
				std::cout << "Added element with indexes [" << i << ";" << currentColumnStart << "]" << std::endl;
				printMatrix(matrix, matrixSize);
			}
			currentColumnStart++;
		}
	}
}

void snakeFill(int **& matrix, const int matrixSize) {
	int currentColumn = 0;
	for (int i = 0; i < matrixSize; ++i) {
		if (currentColumn % 2 == 0) {
			for (int j = 0; j < matrixSize; ++j) {
				matrix[j][currentColumn] = std::rand() % static_cast<int>(std::pow(matrixSize, 2));
				std::cout << "Added element with indexes [" << j << ";" << currentColumn << "]" << std::endl;
				printMatrix(matrix, matrixSize);
			}
		}
		else {
			for (int j = matrixSize - 1; j >= 0; --j) {
				matrix[j][currentColumn] = std::rand() % static_cast<int>(std::pow(matrixSize, 2));
				std::cout << "Added element with indexes [" << j << ";" << currentColumn << "]" << std::endl;
				printMatrix(matrix, matrixSize);
			}
		}
		++currentColumn;
	}
}

void initSquareMatrix(int **& matrix, const int matrixSize) {
	matrix = new int *[matrixSize];
	for (int i = 0; i < matrixSize; ++i) {
		matrix[i] = new int[matrixSize];
	}

	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < matrixSize; ++j) {
			matrix[i][j] = 0;
		}
	}
}

void shuffleMatrix(int **& matrix, const int matrixSize, const int shuffleType) {
	int ** topLeft, ** topRight, ** bottomLeft, ** bottomRight;
	initSquareMatrix(topLeft, matrixSize / 2);
	initSquareMatrix(topRight, matrixSize / 2);
	initSquareMatrix(bottomLeft, matrixSize / 2);
	initSquareMatrix(bottomRight, matrixSize / 2);
	for (int i = 0; i < matrixSize / 2; ++i)
		for (int j = 0; j < matrixSize / 2; ++j)
			topLeft[i][j] = matrix[i][j];

	for (int i = 0; i < matrixSize / 2; ++i)
		for (int j = matrixSize / 2; j < matrixSize; ++j)
			topRight[i][j - matrixSize / 2] = matrix[i][j];

	for (int i = matrixSize / 2; i < matrixSize; ++i)
		for (int j = 0; j < matrixSize / 2; ++j)
			bottomLeft[i - matrixSize / 2][j] = matrix[i][j];

	for (int i = matrixSize / 2; i < matrixSize; ++i)
		for (int j = matrixSize / 2; j < matrixSize; ++j)
			bottomRight[i - matrixSize / 2][j - matrixSize / 2] = matrix[i][j];

	if (shuffleType == 1) {
		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = bottomLeft[i][j];

		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = topLeft[i][j - matrixSize / 2];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = bottomRight[i - matrixSize / 2][j];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = topRight[i - matrixSize / 2][j - matrixSize / 2];
	}
	else if (shuffleType == 2) {
		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = bottomRight[i][j];

		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = bottomLeft[i][j - matrixSize / 2];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = topRight[i - matrixSize / 2][j];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = topLeft[i - matrixSize / 2][j - matrixSize / 2];
	}
	else if (shuffleType == 3) {
		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = bottomLeft[i][j];

		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = bottomRight[i][j - matrixSize / 2];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = topLeft[i - matrixSize / 2][j];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = topRight[i - matrixSize / 2][j - matrixSize / 2];
	}
	else if (shuffleType == 4) {
		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = topRight[i][j];

		for (int i = 0; i < matrixSize / 2; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = topLeft[i][j - matrixSize / 2];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = 0; j < matrixSize / 2; ++j)
				matrix[i][j] = bottomRight[i - matrixSize / 2][j];

		for (int i = matrixSize / 2; i < matrixSize; ++i)
			for (int j = matrixSize / 2; j < matrixSize; ++j)
				matrix[i][j] = bottomLeft[i - matrixSize / 2][j - matrixSize / 2];
	}
	else {
		std::cout << "Error: Unknown shuffle type. Matrix was not changed" << std::endl;
	}
}

void sortMatrix(int **& matrix, const int matrixSize) {
	int * masFromMatrix = new int[matrixSize * matrixSize];
	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < matrixSize; ++j)
			masFromMatrix[matrixSize * i + j] = matrix[i][j];

	for (int i = 1; i < matrixSize * matrixSize; i++) {
		int z = masFromMatrix[i];
		int x = i - 1;
		while (x >= 0 && masFromMatrix[x] > z) {
			masFromMatrix[x + 1] = masFromMatrix[x];
			masFromMatrix[x] = z;
			x--;
		}
	}

	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < matrixSize; ++j)
			matrix[i][j] = masFromMatrix[matrixSize * i + j];
}

void processMatrix(int **& matrix, const int matrixSize,
	const int processType, const int processNum) {
	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < matrixSize; ++j) {
			if (processType == 1)
				matrix[i][j] += processNum;
			if (processType == 2)
				matrix[i][j] -= processNum;
			if (processType == 3)
				matrix[i][j] /= processNum;
			if (processType == 4)
				matrix[i][j] *= processNum;
		}
}

void Lab3() {
	int matrixSize = 0;
	std::cout << "Input matrix size: ";
	std::cin >> matrixSize;
	matrixSize >>= 1;
	matrixSize <<= 1;
	int ** matrix;
	initSquareMatrix(matrix, matrixSize);
	std::cout << "Source matrix:" << std::endl;
	printMatrix(matrix, matrixSize);

	std::cout << "For spiral fill input 1" << std::endl
		<< "For shake fill input 2" << std::endl
		<< "Choose fill type:";
	int fillType = 0;
	std::cin >> fillType;
	if (fillType == 1) {
		spiralFill(matrix, matrixSize);
	}
	else if (fillType == 2) {
		snakeFill(matrix, matrixSize);
	}
	else {
		std::cout << "Error: Unknown fill type" << std::endl;
		return;
	}

	std::cout << "For circle shuffle input 1 " << std::endl
		<< "For diagonal shuffle input 2 " << std::endl
		<< "For vertical shuffle input 3 " << std::endl
		<< "For horizontal shuffle input 4 " << std::endl
		<< "Choose shuffle type:";
	int shuffleType = 0;
	std::cin >> shuffleType;
	shuffleMatrix(matrix, matrixSize, shuffleType);
	std::cout << "Matrix after shuffle:" << std::endl;
	printMatrix(matrix, matrixSize);

	sortMatrix(matrix, matrixSize);
	std::cout << "Matrix after sort:" << std::endl;
	printMatrix(matrix, matrixSize);

	std::cout << "Input process type:";
	int processType = 0;
	std::cin >> processType;
	std::cout << "Input process number:";
	int processNum = 0;
	std::cin >> processNum;
	processMatrix(matrix, matrixSize, processType, processNum);
	std::cout << "Matrix after process:" << std::endl;
	printMatrix(matrix, matrixSize);
}

https://github.com/DmitriyProgSPM/MyLaba1/blob/main/%D0%9E%D1%82%D1%87%D1%91%D1%82%20%D0%BF%D0%BE%20Lab3.docx ОТЧЁТ
