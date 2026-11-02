# 핵심 기능 목록

| ID | 기능 | 참여 Container / Component | 상태 | 문서 |
| --- | --- | --- | --- | --- |
| F-START | 인자 검증과 기본 상태 준비 | C-PHILO / CLI → RESOURCE | 부분 구현 | [시작](startup.md) |
| F-RESOURCE | 자원 초기화, 실패 롤백, 역순 정리 | C-PHILO / RESOURCE ↔ SIM | 부분 구현 | [자원](resources.md) |
| F-SIM | 스레드 생성과 식사·수면·생각 반복 | C-PHILO / SIM ↔ WORKER, POSIX | 설계 | [실행](simulation.md) |
| F-STOP | 사망·목표 달성·생성 실패 시 정지와 회수 | C-PHILO / SIM ↔ WORKER → RESOURCE | 부분 구현 | [종료](simulation.md#f-stop--정지와-회수) |

흐름의 모든 Component는 [C-PHILO](../containers/philo.md) 내부에 있다. 현재 구현과 목표 동작을 각 문서에서 구분한다.
