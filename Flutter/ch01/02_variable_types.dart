/*
  날짜 : 2025.10.23
  이름 : 서현우
  내용 : Dart변수와 타입
 */


void main(){

  //변수와 기본 타입
  String name = '홍길동'; // '',"" 상관없음
  int age = 23;
  double height = 177.2;
  bool isStudent = true;
  num score = 100; //숫자형(int, double 포함하는 상위타입, 합친거)
  var address = '부산시'; //자동 추론 타입(컴파일 시점, 최초 한번 타입이 정해지면 변경 불가)
  dynamic etc = '기타';  //자동 동적 타입(런타임 시점, 최초 한번 타입이 정해져도 변경 가능), dynamic으로 주로 씀

  print('이름 : ${name}\n나이 : ${age}\n키 : ${height}\n학생여부 : ${isStudent}\n주소 : ${address}\netc:${etc}');
  //address = 1111; >> var로해서 이제 String로 고정된거
  etc = 1; //얘는 dynamic라서 됨
  print('etc 변경 후 : ${etc}');

  //Nullable 타입 (기본적으로 null 불가인데 ? 키워드로 null 가능하게끔 해줌)
  //Dart의 기본 변수는 모두 Non-Nullable, null 취급하기위해서 타입 뒤에 ?표기하여 가능토록 함
  String? value1 = null;
  int? value2;

  print('value1 : ${value1}, value2 : ${value2}');


  //타입 확인
  print('name 타입 : ${name.runtimeType}');
  print('age 타입 : ${age.runtimeType}');
  print('height 타입 : ${height.runtimeType}');
  print('isStudent 타입 : ${isStudent.runtimeType}');
  print('score 타입 : ${score.runtimeType}');
  print('address 타입 : ${address.runtimeType}');
  print('etc 타입 : ${etc.runtimeType}');
  print('value1 타입 : ${value1.runtimeType}');
  print('value2 타입 : ${value2.runtimeType}');



  //타입 변환
  String strNum = '2025';
  int intNum = int.parse(strNum);

  double price = 19.9;
  int intPrice = price.toInt();
  print('roundePrice : ${intPrice}');

  int count = 122;
  String strCount = count.toString();
  print('strCount : ${strCount}');

  //상수
  final num1 = 100; // 런타입 상수 ,실행시간에 결정
  const num2 = 200; //컴파일 타입 상수, 클래스 멤버로 사용

  final today = DateTime.now();

  print('todaty : ${today}');

//문자열
  String hello = "hello CDART";
  String welcome ='''
  welcome dart!
  welcome world!
  welcome flutter!
  ''';

  print(hello);
  print(welcome);

  String escape = "나는 생각한다. \'Dart\' 는 재밌다.";
  String escape2 = r'escape test c:\user\aaa';
  print(escape);
  print(escape2);

  String rawStr = r'C:\users\flutter\bin';
  print(rawStr);

  String fName = '길동';
  String lName = '홍';
  String fullName = lName + fName;
  print('이름: ' + fullName);
  print('이름: $lName$fName'); // 문자열 보간

  String word = 'Flutter';
  print('문자열 길이: ${word.length}');
  print('첫 번째 문자: ${word[0]}');

  String text = '   Dart Language   ';
  print('원본: [$text]');
  print('소문자: ${text.toLowerCase()}');
  print('대문자: ${text.toUpperCase()}');
  print('공백 제거: [${text.trim()}]');
  print('문자 포함 여부: ${text.contains('Dart')}');
  print('문자열 교체: ${text.replaceAll('Dart', 'Flutter')}');

  String sentence = '서울,대전,대구,부산,광주';
  var cities = sentence.split(','); //리스트로 줌
  print('나눈 결과: $cities');
  print('다시 합치기: ${cities.join('/')}');

}
