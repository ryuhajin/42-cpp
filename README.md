# CPP Modules · 42 Seoul

> C++98 기초부터 OOP, 템플릿, STL까지 단계적으로 다루는 CPP Module 00–09 과제 모음

## 개요
모듈마다 C++의 한 가지 주제를 정해 여러 개의 연습 문제(`exNN/`)로 익힌다.
모든 코드는 `-std=c++98 -Wall -Wextra -Werror`로 컴파일되며, Module02 이후 클래스는 Orthodox Canonical Form
(기본 생성자, 복사 생성자, 복사 대입 연산자, 소멸자)을 기본으로 작성했다.

## 모듈 구성
| 모듈 | 주제 | 연습 문제 |
|---|---|---|
| 00 | 네임스페이스, 클래스, 멤버 함수, iostream | ex00 `megaphone`(인자를 대문자로 출력) · ex01 `PhoneBook`(최대 8개 `Contact`, ADD / SEARCH / EXIT) |
| 01 | 메모리 할당, 포인터와 참조, 멤버 함수 포인터 | ex00 `newZombie`(힙) / `randomChump`(스택) · ex01 `zombieHorde`(`new[]`) · ex02 포인터와 참조의 주소·값 비교 · ex03 `HumanA`(참조) / `HumanB`(포인터)와 `Weapon` · ex04 파일 내 문자열 치환 → `<file>.replace` · ex05 `Harl` 멤버 함수 포인터 배열 · ex06 `harlFilter`(`switch` fall-through) |
| 02 | Ad-hoc 다형성, 연산자 오버로딩, OCF | 소수부 8비트 고정소수점 `Fixed` · ex00 OCF와 raw bits · ex01 int/float 생성자, `toFloat` / `toInt`, `operator<<` · ex02 비교·산술·증감 연산자, static `min` / `max` |
| 03 | 상속 | ex00 `ClapTrap` · ex01 `ScavTrap` · ex02 `FragTrap` · ex03 `DiamondTrap`(`virtual public ClapTrap`로 다이아몬드 상속) |
| 04 | 서브타입 다형성, 추상 클래스, 인터페이스 | ex00 `Animal` / `Dog` / `Cat`과 가상 함수가 없는 `WrongAnimal` 비교 · ex01 `Brain` 깊은 복사 · ex02 순수 가상 함수로 `Animal`을 추상화 · ex03 `AMateria`, `ICharacter`, `IMateriaSource`(`Ice`, `Cure`, `Character`, `MateriaSource`) |
| 05 | 예외 처리 | ex00 `Bureaucrat`(`GradeTooHigh/LowException`) · ex01 `Form` 서명 · ex02 추상 `AForm`과 `Shrubbery` / `Robotomy` / `PresidentialPardon` 폼 · ex03 `Intern::makeForm`(생성 함수 포인터 테이블) |
| 06 | C++ 캐스트 | ex01 `Serializer`(`reinterpret_cast`로 `Data*` ↔ `uintptr_t`) · ex02 `dynamic_cast`로 포인터/참조의 실제 타입 식별 |
| 07 | 템플릿 | ex00 `swap` / `min` / `max` · ex01 `iter`(const / non-const 오버로드) · ex02 `Array<T>`(범위 밖 접근 시 `std::out_of_range`) |
| 08 | 템플릿 컨테이너, 반복자, 알고리즘 | ex00 `easyfind`(`std::find`) · ex01 `Span`(`addNumbers` 반복자 범위 추가, 최단/최장 간격) · ex02 `MutantStack`(`std::stack`에 반복자 추가) |
| 09 | STL 활용 | ex00 `btc`(`std::map` + `lower_bound`로 가장 가까운 이전 날짜의 환율 적용) · ex01 `RPN`(`std::stack` 역폴란드 표기 계산) · ex02 `PmergeMe`(Ford-Johnson 병합-삽입 정렬을 `std::vector`, `std::deque`로 각각 구현하고 소요 시간 비교) |

`cpp09_ex02_test/`는 Module09 ex02의 실험용 사본이다. 삽입 순서를 출력하는 디버그 함수(`printInsert`),
Ford-Johnson 알고리즘 정리 노트(`study.md`), 실행 출력 예시(`out`)가 들어 있다.

## 빌드 & 실행
각 연습 문제 폴더에 개별 `makefile`(또는 `Makefile`)이 있다.

```bash
cd Module00/ex00 && make && ./megaphone "shhhhh... I think the students are asleep..."
cd Module01/ex04 && make && ./ex04 test.txt old new     # → test.txt.replace
cd Module09/ex00 && make && ./btc input.csv             # data.csv를 환율 DB로 사용
cd Module09/ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
cd Module09/ex02 && make && ./PmergeMe 3 5 9 7 4
```

실행 파일 이름은 대부분 `ex00`, `ex01` …이며, 예외는 `megaphone`, `Phonebook`, `harlFilter`, `btc`, `RPN`, `PmergeMe`, `PmergeMeT`이다.

## 구조
```
cpp/
├── Module00/ ... Module09/
│   └── exNN/            # 소스(.cpp/.hpp) + makefile
└── cpp09_ex02_test/     # PmergeMe 실험용 코드와 노트
```

42 Seoul 공통 과정 과제.
