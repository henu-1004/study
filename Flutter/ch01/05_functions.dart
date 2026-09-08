/*
  내용 : dart함수
 */

void hello(){
  print('hello dart!');
}

int add(int a, int b){
  return a+ b;
}

var greet = (String name){
  return 'Greeting ${name}!';
};

int plus(int a, int b) => a+b;
int minus(a, b) => a-b;

//고차함수
//매개변수로 함수를받는경우
int calc(int x, int y, int Function(int, int) operation){ //int Function(int, int) operation > 리턴타입은 인트, 펑션매개변수로 인트두개, 그거에 또 동작하게 들어오는 함수가 오퍼레이션
  return operation(x,y);
}
//반환타입으로 함수를 보내는 경우
Function creatHello(String name){
  return () => "Hello, ${name}";
}


//이름이 있는 매개변수 함수,{중괄호}매개변수
void person1({String hello = 'hello', String? name}){ //hello에 'hello'로 기본값지정한거
  print('person1 $hello, $name');
}

void person2(String name, {String? hello}){//이건 name은 일반매개변수인형태
  print('person2 $hello, $name');
}

void person3(String name, {String? hello, required int age}){
  print('person2 $hello, $name, $age');
}

//선택적 위치 매개변수 함수, [대괄호]매개변수
void user1(String name, [int age = 0]){
  print('user1 $name, $age');
}

void user2(String name, [int? age, String? address]){
  print('user2 $name, $age, $address');
}

void user3(String name, [int age=0, String address='Unknown', String? job]){
  print('user3 $name, $age, $address, $job');
}


void main(){

  //기본함수
  hello();

  //매개변수와 반환값이 있는 함수
  int result1=add(1,2);
  int result2=add(2,3);
  print('result1 : ${result1}');
  print('result2 : ${result2}');

  //익명 함수
  print(greet('김유신'));
  print(greet('김춘추'));

  //화살표 함수(람다식)
  int rs1 = plus(2, 3);
  int rs2 = minus(2,3);

  print('rs1 : $rs1');
  print('rs2 : $rs2');

  //고차함수(함수를 매개변수로 전달받거나 반환하는 함수)
  int result = calc(10,5,minus);
  print('result : $result');

  var greeting = creatHello("홍길동");
  print(greeting());


  //이름이 있는 매개 변수(Named Parameter, {중괄호} 매개변수)
  person1();
  person1(name: '홍길동');
  person1(name: '바바',hello: '헬로변경');
  person2('김유신');
  person2('김춘추', hello: '반갑다.');
  person3('장보고',age:21,hello:'반갑습니다.'); //이름이있는 함수끼리의 순서는 신경안쓰고 선언 넘겨도 괜찮음, 이름없는애랑도 딱히 순서연관없을듯 but 이름없는애들끼리는 순서 잘 지켜야함


  //선택적 위치 매개 변수(Optional Positional Parameter, [대괄호] 매개변수)
  user1('김유신');
  user1('김춘추', 21);
  user2('장보고');
  user2('강감찬',23);
  user2('이순신',31,'서울');
  user3('정약용');
  user3('김아무개', 44, '부산','엔지니어'); //선택적위치는 선택적인애들끼리의 순서는 지켜져야함


}
