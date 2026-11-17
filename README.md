# DirectX-SANNABI

상용 엔진 없이 DirectX 11로 만든 2D 엔진 위에 사슬팔 액션 게임 '산나비'의 핵심 조작을 구현한 개인 프로젝트입니다.
어소트락 게임 아카데미 과정에서 배운 엔진 구조를 바탕으로 직접 작성했습니다.

- 기간: 2025.10 ~ 2025.12
- 인원: 1명
- 언어: C++, HLSL
- 라이브러리: Direct3D 11, DirectXMath, DirectXTex, FMOD, Win32 API
- 영상: https://www.youtube.com/watch?v=whA1HWzl_Xs

## 엔진 구조

| 영역 | 주요 클래스 | 내용 |
|---|---|---|
| 코어 | `CGameManager`, `CDevice`, `CTimer` | 윈도우 생성, D3D11 디바이스·스왑 체인, 고해상도 타이머 기반 프레임 루프 |
| 객체 모델 | `CObject`, `AActor`, `CComponent`, `CSceneComponent` | Actor가 Component를 소유하는 구조, 부모-자식 트랜스폼 계층 |
| 메모리 관리 | `CObject`, `TSharedPtr` | 기반 클래스의 참조 카운트와 직접 작성한 침습형 스마트 포인터 |
| 렌더링 | `CRenderManager`, `CShaderManager`, 상수 버퍼 클래스 | HLSL 셰이더, 렌더 레이어별 Z 순서, 알파 블렌딩 |
| 좌표 변환 | `CSceneComponent`, `CCameraComponent`, `CTransformCBuffer` | 월드 = 크기 × 회전 × 이동, 카메라 축으로 뷰 행렬 구성, 직교·원근 투영 |
| 충돌 | `CCollision`, `CCollisionQuadTree`, `CProfileManager` | AABB·OBB·원·선분 판정, 쿼드트리 공간 분할, 채널·프로파일 |
| 애니메이션 | `CAnimation2D`, `CAnimation2DSequence` | 프레임별 UV 치환, 프레임 노티파이 |
| 디버그 | `CLog` | 콘솔·출력 창 실시간 로그, 텍스트 파일 저장 |

## 게임플레이

| 기능 | 주요 파일 |
|---|---|
| 이동 상태 머신 (지면·낙하·벽·스윙·돌진·피격·사망) | `Player.cpp`, `PlayerMovement.cpp` |
| 사슬팔 조준: 마우스 방향 ±30° 안의 가장 가까운 대상 선택 | `Player.cpp` |
| 사슬 발사·회수 | `Grab.cpp` |
| 적 (소총형, 산탄형) | `RifleEnemy.cpp`, `ShotGunEnemy.cpp` |

### 사슬 스윙

물리 엔진 없이 사슬에 매달려 흔들리는 운동을 구현했습니다 (`CPlayerMovement::Swing`).

- **원운동**: 캐릭터에서 갈고리로 향하는 벡터와 화면에 수직인 Z축 벡터를 외적해 원의 접선 방향을 구하고, 이를 이동 방향으로 사용
- **진자 운동**: 사슬 각도의 사인 값을 중력가속도에 곱해 매 프레임 속력에 더함
- **회전 방향**: 사슬이 걸린 순간 캐릭터가 갈고리의 어느 쪽에 있는지로 Z축 부호를 결정

## 저장소에 포함되지 않은 것

- **게임 에셋**: 스프라이트, 배경, 사운드, OST는 원작 게임 '산나비'의 저작물이라 제외했습니다.
- **FMOD SDK**: 라이선스상 재배포하지 않았습니다. 빌드하려면 FMOD Engine을 설치하고 헤더와 라이브러리를 프로젝트에 추가해야 합니다.
- **DirectXTex 라이브러리**: 헤더만 포함했고, `.lib`는 [DirectXTex](https://github.com/microsoft/DirectXTex)를 빌드해 `Bin` 폴더에 두어야 합니다.

에셋이 없으므로 이 저장소만으로는 게임을 실행할 수 없습니다. 플레이 모습은 위 영상에서 볼 수 있습니다.
