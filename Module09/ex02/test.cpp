bool isValidNumber(const char* str) {
    char* endPtr;
    errno = 0; // errno 초기화

    // strtol을 사용하여 문자열을 long 타입으로 변환
    long value = std::strtol(str, &endPtr, 10);

    // 문자열이 빈 경우 또는 숫자가 아닌 경우
    if (endPtr == str) {
        std::cerr << "No digits were found." << std::endl;
        return false;
    }

    // endPtr가 문자열의 끝을 가리키지 않으면, 숫자 이외의 문자가 포함됨
    if (*endPtr != '\0') {
        std::cerr << "Non-digit characters were found: " << endPtr << std::endl;
        return false;
    }

    // 변환된 숫자가 범위를 초과한 경우
    if (errno == ERANGE || value < 0 || value > INT_MAX) {
        std::cerr << "Number out of range." << std::endl;
        return false;
    }

    return true;
}



	std::vector<std::size_t> matchPlayers(ContainerType::iterator begin, std::size_t winnerCount, bool isOdd)
	{
		std::vector<std::size_t> opponent(winnerCount + isOdd);
		const std::size_t opponentGap = winnerCount + isOdd; // 쌍을 이루는 상대방과 인덱스 상의 거리
		for (std::size_t idx = 0; idx < winnerCount; ++idx)
		{
			std::size_t opponentIdx = opponentGap + idx;
			opponent[idx] = opponentIdx;
			if (begin[idx].first < begin[opponentIdx].first)
			{
				std::swap(begin[idx], begin[opponentIdx]);
			}
		}
		if (isOdd)
		{
			opponent[winnerCount] = winnerCount;
		}
		return opponent;
	}

void VectorPmergeMe::MakePair(std::vector< std::vector<int> > &main_chain, std::vector< std::vector<int> > &pending_chain)
{
    bool is_odd = main_chain.size() % 2 == 1 ? true : false;
    size_t gap = main_chain.size() / 2;
    for (size_t i = 0; i < gap; i++)
    {
        pending_chain.push_back(main_chain.back());
        pending_chain[i].push_back(i);
        main_chain.pop_back();
        main_chain[i].push_back(i);
    }

    if (is_odd)
    {
        main_chain[gap].push_back(gap);
        pending_chain.push_back(main_chain.back());
        pending_chain[gap][0] = -1;
    }
}

void	PmergeMe::MakePair(Vector& vector)
{
	std::size_t	size = vector.size();
	std::size_t	j = size / 2;
	for (std::size_t i = 0; i < size / 2; ++i)
	{
		if (vector[i].first < vector[j].first)
		{
			Pair	temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
		}
		++j;
	}
}
