
/*
 내용 Dart연산자
 */

void main(){

  //////////////////////////////
  //기본연산자
  //////////////////////////////
  int a = 10;
  int b = 3;

  // 산술 연산자
  print(a + b);   // 13
  print(a - b);   // 7
  print(a * b);   // 30
  print(a / b);   // 3.3333333333333335 (double)
  print(a ~/ b);  // 3 (정수 나눗셈)
  print(a % b);   // 1 (나머지)

  // 대입 연산자
  int x = 5;

  x += 3; // x = x + 3
  print(x); // 8

  x *= 2; // x = x * 2
  print(x); // 16

  // 증감 연산자
  x++;
  print(x); // 8

  --x;
  print(x); // 8

  // 비교 연산자
  print(a == b);
  print(a != b);
  print(a > b);
  print(a < b);
  print(a >= 10);

  // 논리 연산자
  print(a > 1 && b > 1); // false
  print(a < 10 || b < 11); // true
  print(!(a > b));           // false

  // 삼항 연산자
  String result = a > b ? 'a가 크다' : 'b가 크다';
  print(result); // a가 크다

  //타입검사 연산자
  dynamic value = 'hello';
  print('value is int : ${value is int}' );
  print('value is int : ${value is String}' );
  print('value is int : ${value is! String}' );

  //////////////////////////////
  //null관련 연산자
  //////////////////////////////

  //Null 병합연산자 > nullable변수는 none에 대입하려면 ?? 라는 병합연산자 사용해야함
  int? value1;
  int result1 = value1 ?? 100; //value1이 null이면 100을 대입 > null 병합 연산자
  print(result1);

  value1 = 50;
  int result2 = value1 ?? 200; //최신 Dart 컴파일러는 자동으로 타입 체크를 통해 ?? 병합연산자 생략해도 에러안남
  print(result2);

  int? num1;
  int? num2;
  int? num3;

  int result3 = num1 ?? num2 ?? num3 ?? 1000; //if문처럼 num1이 널이면 num2걔도널이면 num3 걔도널이면 1000
  print('result3 : ${result3}');

  num2 = 2;

  int result4 = num1 ?? num2 ?? num3 ?? 1000; //if문처럼 num1이 널이면 num2걔도널이면 num3 걔도널이면 1000
  print('result4 : ${result4}');

  //Null 대입연산자
  num3 ??= 3; //num3가 null이면 3으로 초기화
  print('num3 : ${num3}');


  //Null 접근연산자
  String? nullableString;
  print(nullableString?.toUpperCase()); //null 아닐 경우 toUpperCase()호출

  nullableString = 'hello dart';
  print(nullableString?.toUpperCase()); //null 아닐 경우 toUpperCase()호출


  //Null 강제 연산자
  int? maybeNumber =3;
  int mustNotNullNumber = maybeNumber!;//nullable 변수를 non-nullable 변수에 직접대입은 안됨, 그래서 null이 아님을 명화히 보장하기위해 ! 사용
  //예전다트버전에서는 nullable를 nonenullable에 대입못함, 지금은 가능, but 더 확실하게 표현하기위해 ! 표기로 얘는 null아니라고 표시
  print(mustNotNullNumber);

}