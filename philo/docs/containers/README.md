# C4 구조

- 구현 상태: 부분 구현.
- 설계 범위: 단일 Container와 내부 Component 책임·인터페이스 초안.

## System Context · L1

```mermaid
flowchart LR
    user[사용자] -->|명령행 인자| system[Philosophers 시뮬레이션]
    system -->|상태 로그와 종료 코드| user
```

상태 로그는 설계이며 현재 출력 구현은 없다. 외부 서비스나 영속 저장소는 없다.

## Container · L2

```mermaid
flowchart LR
    user[사용자 / 셸] -->|argc, argv| philo["C-PHILO: philo · C / pthread"]
    philo -->|stdout 상태 로그 · 설계| user
    philo -->|프로세스 종료 코드| user
    philo -->|스레드·mutex·메모리 API| runtime[POSIX / C 런타임]
```

| ID | Container | 책임 | 상세 |
| --- | --- | --- | --- |
| C-PHILO | philo 실행 프로세스 | 입력 검증, 자원 관리, 철학자 실행과 종료 | [계약 및 내부 Component](philo.md) |

단일 Container이므로 Container 간 네트워크 통신은 없다. 다중 스레드는 동일한 주소 공간의 `t_data`와 `t_philo`를 공유한다.

## 설계 진입점

- [C-PHILO 상세](philo.md): CLI·RESOURCE·SIM·WORKER·MONITOR·TIME·LOG의 책임과 계약.
- 실행 모델: 메인 스레드에서 조정·감시, 철학자별 worker N개.
- 다음 단계: [실행 흐름](../flows/simulation.md)의 시간·잠금·정지·회수 계약 구체화.
- 미구현 설계와 현재 코드 상태 구분. 파일 분리는 Component 계약 확정 후 결정.
