# 빅데이터

## 빅데이터를 가치 있게 만드는 요소

* 기업은 기술을 활용하여 소비자가 생성한 신호를 바탕으로 보다 정확한 정보에 입각한 의사 결정을 내리게 해줌.
* 빅데이터를 사용하면 소비자 전체가 아닌 각 소비자의 목소리를 들을 수 있다.
* Twitter,Facebook : 공개적으로 접근 가능한 데이터를 풍부하게 생성 -> 회사는 사람들의 구매내역,무엇을 검색,무엇을 봤는지,무엇에 관심있는지
볼수 있다.

* 추천 엔진
  * 사용자 패턴과 제품 기능을 활용하여 사용자 환경을 풍부하게 하기 위해 가장 적합한 제품을 예측.
  * ex) Netflix는 시청 기록을 기반으로 새로운 프로그램을 시청할 것을 권장.

* 감정 분석
  * 행사나 제품에 대한 느낌을 분석
  * 아마존은 제품에 대한 후기와 동향을 지켜보면서(자연어 처리 및 기타 분석 방법 기술을 사용하여) 개인이나 대중의 일반적인 견해를 분석.
  
* 모든 비즈니스는 끊임없이 변화하는 풍경을 포착하기 위해 소비자의 집단 행동을 이해하고자 한다.
* 빅데이터는 많은 응용 분야에서 더 높은 정밀도를 갖는 모델을 가능하게 할만한 거대한 잠재력을 갖고 있다.
* 이러한 정확한 모델은 비즈니스에 영향을 주고 변화시킨다.

## 빅데이터의 출처

* 실제 가치는 빅데이터 소스의 스트림을 서로 결합하고 이를 분석하여 새로운 통찰력을 창출한 다음 빅데이터 자체로 다시 돌아오는 경우가 많다.
* 단일 데이터 소스 자체만으로는 유용하지 않다.

* 기계에 의해 생성 된 빅데이터
  * 활동 추적기
  * 항공기의 센서 : 항공기 관리 및 비행 안전을 보는 새로운 방법을 만들어 냄.
  
* 빅데이터 기반의 통찰력을 조직에 통합하려는 경우 새로운 전략과 새로운 작업 방식을 정의.

* 사람이 생성한 빅데이터(비정형화된 데이터)
  * 대부분의 데이터는 구조화되지 않음.
  * 이런 데이터들을 사용하기 위해 Hadoop이라는 오픈 소스의 빅데이터 프레임 워크를 사용.(대량의 분산 정보를 처리)
  * storm과 spark는 빠른 속도로 생성된 실시간 데이터를 처리하는 오픈 소스 프레임 워크.
  * 구조화 되지 않은 데이터는 기존의 관계형 데이터베이스 모델에 맞지 않음. 그래서 기업들은 하이브리드 접근법 사용
  * 소규모 구조화된 데이터가 관계형 데이터베이스에 남고 대형 구조화되지 않은 데이터 세트는 클라우드의 nosql 데이터베이스에 저장.
  * nosql 솔루션 : 데이터 사용 방법과 관련된 문제와 목적에 맞게 확장 가능한 접근을 위해 데이터를 구성 가능.

* 빅데이터에서 가치를 창출 하기 전에 일련의 단계를 거쳐야 한다. 엑세스 -> 저장 -> 정리 및 분석 ( 각 단계를 다른 레이어로 실행)
  
* 조직에서 생성된 데이터
  * 매우 유용하고 신뢰할 수 있으며 귀중한 정보기는 하지만 조직은 잠재력을 최대한 활용하기 위해 정보 격차를 해체하는데 주의를 기울어야 함.
  * 다른 데이터 유형과 결합할 때 이득이 생김.

* 다양한 데이터의 통합
  * 서로 다른 형식으로 데이터를 통합하면 설명하는 특징이 더 풍부해짐.
  
## 빅데이터의 특성

* 볼륨
  -순수 크기 및 지수 증가와 관련된 빅데이터의 차원
  -최종 제품의 품질을 향상시키기 위해 어떻게 더 많은 양의 데이터를 활용할 것인가
  -빅데이터로 작업 할 때의 과제는 스토리지,접근 및 처리와 관련된 비용,확정성 및 성능

* 다양성

* 속도
  -빅데이터가 생성되는 속도가 증가하는 것, 데이터 저장 및 분석에 필요한 속도가 증가하는 것
  -실시간 처리: 실시간으로 이상을 탐지하여 즉각적인 조치를 취함.
  -빅데이터의 속도에 주의를 기울여야 함, 스트리밍 데이터는 다양한 속도로 생성, 실시간으로 분석하면 민첩성과 적응성이 높아져 얻고자 하는 이점을 극대화 할 수 있다.
  
* 진실성
  -데이터의 품질
  -데이터를 통합하기 시작하면서 더 복잡해지고 불확실해짐.
  
* 원자가(valence)
  -유대 관계, 연결된 데이터가 많을수록 더 높은 연결성을 갖음
  -연결된 데이테 세트가 시간과 양에 따라 어떻게 변할 수 있는지 모델링하고 예측할 필요가 있음.
* 가치

## 빅데이터에서 가치 창출

* 통찰력을 이끌어내기 위해 생성된 모델들을 개선하는 프로세스를 수반
* 과거 및 현재 정보를 분석하여 행동을 만들어냄, 미래에 대한 실행 가능한 정보의 생성
* 비즈니스 의사 결정에 증거 기반의 통찰력을 사용할수 있다는 점.

## 빅데이터 전략 구축

* 목표,정책,계획,행동
* 팀의 목표가 무엇인지 먼저 정의하는 것이 중요
* 데이터 엑세스 및 통합에 대한 장벽은 제거

## 데이터 과학 프로세스의 단계

* 데이터 획득 - 데이터 준비 - 데이터 사전 처리 - 데이터 분석 결과 평가

* 데이터 수집
  -사용 가능한 데이터를 결정
  -웹 사이트에서 가져옴(다양한 형식과 서비스 포함)
  
* 데이터 탐색
  -데이터의 여러 변수 간의 종속성을 탐색
  -특이치는 희귀한 사건을 찾을 수 있게 해줌.
  -요약 통계 - 데이터의 성격을 알 수 있다.
  
* 데이터 전처리
  -데이터 품질 문제를 해결하기 위해 데이터를 정리, 원시 데이터를 변환하여 분석에 적합하도록 만드는 것
  -중복 레코드를 병합
  -집계 데이터(Aggregate data)는 일반적으로 분석의 도움을 줄 수 있는 가변성이 적은 데이터를 생성
  -일일 판매 수치가 아닌 주,월 단위로 집계.
  -들어간 쓰레기, 나온 쓰레기

* 데이터 분석
  -이진 분류, 회귀, 클러스터팅, 연관 분석, 그래프 분석
  -회귀: 모델이 범주가 아닌 숫자 값을 예측하는 경우
  -클러스터링: 목표가 유사한 항목을 그룹으로 구성
  -연관 분석: 항목 또는 이벤트 내의 연관을 캡처하는 규칙 세트를 제안, 규칙은 항목이나 이벤트가 함께 발생한느 시기를 결정하는데 사용.
  -그래프 분석: 많은 entity를 갖고 있고 entity 사이 연결이 있을 때 발생.
  -모델링 : 문제의 유형에 따라 적합한 분석기법으로 나열한 것 중에 하나를 고르는 것으로 시작.
  
  * 모델 구성을 위한 데이터 세트를 나누고, 나머지는 모델을 평가함.
  * 모델을 평가하는 것은 사용한 분석 기법의 유형에 따라 다름.
  
* 결과 전달
  -분석 결과를 보고 보고 할 것을 결정
  -핵심은 다음 조치는 무엇일지를 결정하기 위함.
  -많은 시각화 도구가 있다.
  
* 통찰력을 실행으로 전환
  -데이터 내에서 실행 가능한 통찰력을 찾고 비즈니스를 개선.
  -수행할 작업을 결정 했으면, 다음 단계는 작업을 구현하는 방법을 파악.
  
  
## 분산 파일 시스템

* 데이터 접근을 처리하고 이를 수행할 수 있는 시스템을 갖추는 것.
* 데이터 복제를 통해 접근의 확장성에 도움이 됨, 반면 시간이 지남에 따라 데이터를 변경하기가 어려움.
* 분산 파일 시스템은 많은 노드에서 데이터의 분할 및 복제를 통해 데이터 확장성, 내고장성 및 높은 동시성을 제공

* 상용 클러스터 : 평균 수의 컴퓨팅 노드가 있는 경제적인 병렬 컴퓨터
  -컴퓨팅 노드는 고속 네트워크를 통해 서로 연결되어 있는 랙에서 클러스터링.
* 분산 컴퓨팅 : 이러한 클러스터 중 하나 이상을 컴퓨팅 하는 것.
* 이러한 아키텍처로 데이터 병렬성을 구현, 중복 데이터 저장 및 실패한 개별 병렬 작업의 재시작을 통해 문제들 해결.

## 빅데이터를 위한 프로그래밍 모델

* 빅데이터를 사용하는 분산 파일 시스템 위에 효율적으로 작동하는 컴퓨터 프로그램을 작성하고 그것이 잠재적인 문제를 쉽게 극복하도록 하게함.
* 많은 병렬 작업을 한 번에 스케줄링 하는 것을 의미.
* MapReduce

## Hadoop

* 대량 하드웨어 데이터를 상품 하드웨어에 저장할 수 있는 확장성을 제공
* 충돌 및 오류를 정상적으로 복구 할 수 있는 능력
* 특정 유형의 데이터에 대해 이러한 다양한 데이터 유형을 처리할 수 있는 능력
* 공유 환경을 가능하게 하는 능력.

* Hadoop ecosystem
  -많은 무료 컨텐츠
  -레이어 다이어그램으로 구성하여 기능을 이해 가능.
  -HDFS: 확장 가능하고 안정적인 스토리지를 제공, 필수 하드웨어를 추가하여 스토리지 용량을 늘려 리소스를 확장 가능
  -YARN: HDFS 스토리지에 대한 유연한 스케쥴링 및 리소스 관리 기능
  -MapReduce: 병렬 컴퓨팅을 단순화 하는 프로그래밍 모델, 여기에 매핑 및 축소 기능만 제공하면됨.(동기화 및 스케줄링의 복잡성 대신 처리)
    -Hive,Pig는 관계형 대수 및 데이터 흐름 모델링을 사용하여 보완.
  -Storm,spark는 빅데이터의 메모리 처리에 있어서 실시간으로 구축.
  
## HDFS

* 대규모 데이터 세트에 대한 확장성, 하드웨어 고장에 대처하는 신뢰성을 제공
* 매우 큰 파일에 병렬 엑세스
* 내고장성 기능(데이터 손실을 방지하기 위해 다른 노드에 파일 블록을 복제하거나 복사본을 만듬), 기본적으로 3개 유지
* 입력 파일 형식과 출력 파일 형식을 지정해야함.
* NameNode, DataNode로 구성, master-slave 관계, namenode는 메타 데이터를 담당, datanode는 블록 스토리지를 제공
* namenode는 파일의 내용을 저장할 노드를 결정하고, 매핑을 기억.
* datanode는 클러스터의 각 노드에서 실행.

## YARN

* HDFS 위에 있는 리소스 관리 레이어
* 응용프로그램과 상호작용하고 그것들의 사용을 위해 자원을 스케줄링 함.
* 빅데이터에 적합하다고 생각되는 도구를 사용할 수 있다.

* 재검토하는 시점?
 -임의 데이터에 접근하기 어려움.
 -많은 알고리즘의 확장성에 뛰어나지만, 하나의 모델일 뿐이며 빅데이터를 처리하고 관리하는데 있어 모든 문제를 해결하지는 않음.
 -작은 데이터 셋, 특정 하드웨어 유형을 요구하는 고급 알고리즘, 작업 수준 병렬 처리, 무작위 데이터 엑세스에 적합하지 않음.

## mapreduce

* Hadrrop ecosystem의 프로그래밍 모델, 코드 실행을 병렬로 단순화
* Hive는 관계형 데이터 모델링에 도움이 되는 sql 형 인터페이스를 제공
* Pig는 프로세스 맵 모델링에 도움이 되는 기능을 추가하는 고급 데이터 흐름 언이이다.
* map -> shuffle and sort -> reduce
* 데이터가 자주 바뀌는 경우 매번 입력 데이터 집합 전체를 읽으므로 속도가 느림.
* 의존성이 있는 계산은 맵리듀스로 실행하지 못함.

## hadoop이용

* virtualbox에 cloudera 이미지 가져와서 부팅
 - 오류가 생겨서 cmd에 bcdedit /set hypervisorlaunchedsetoff 명령 실행 후 os 다시시작함.
* 텍스트파일 다운 받은 후 hadoop fs -copyFromLocal words.txt 로 hdfs로 옮김.
* hadoop jar /usr/jars/hadoop-examples.jar 명령을 통해 응용프로그램 목록을 볼 수 있음.
* hadoop jar /usr/jars/hadoop-examples.jar wordcount words.txt out 명령으로 WordCount를 실행
 -hadoop은 map 및 Reduce의 측면에서 진행 상황을 인쇄.
* out 파일을 보면 out_SUCCESS로 성공적으로 실행되었음을 확인 가능, out part-r-00000를 실행하여 로컬 시스템에 복사
* more local.txt로 살펴보면 입력 파일에 있는 단어의 발생수를 확인 가능.