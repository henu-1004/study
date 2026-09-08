/*
내용 : dart 객체지향 프로그래밍
 */

class Person{
  String? name;
  int? age;

  void introduce(){
    print('name : ${name}, age : ${age}');
  }
}

class User{
  //속성명 앞에 _ 표기로 private 선언
  String _name;
  String _birth;
  int? _age;

  //클래스 속성 static을 의미
  static int total = 0;

  //지연초기화 속성, 속성을 생성자에서 초기화 하지않고, 객체를 생성 후 특정 메서드에서 초기화
  late String _email;

  //기본생성자
  User(this._name, this._birth);

  //명명된 생성자(Named Constructor), 초기화 목록 생성자
  User.withAge(String name, String birth, int age) : this._name = name, this._birth =birth, this._age =age{
    //객체 생성 후 필요한 로직 처리
    total++;
    print('User.withAge 호출...');
  }

  User.guest(this._name) : this._birth = 'Unknown',this._age=0;

  //factory 생성자 (객체를 캐싱하는 생성자)
  static final Map<String, User> _cache={}; // User 객체 캐싱하는 저장소
  factory User.createUser(String name, String birth){
    if(_cache.containsKey(name)){
      return _cache[name]!; //캐시에서 객체 반환
    }
    else{//캐시에 없으면
      var newUser = User(name, birth);
      _cache[name] = newUser; //캐시저장
      return newUser;
    }
  }

  //Getter/Setter
  String get name => _name;
  String get birth => _birth;
  int? get age => _age;

  set name(String name){
    _name = name;
  }

  set birth(String birth){
    _birth + birth;
  }

  set age(int age){
    _age = age;
  }

  //메서드
  void hello(){
    print('name : $_name, birth : $_birth, age : $_age, email : $_email');
  }

  //late 속성을 초기화 하는 메서드
  void initEmail(String value){
    if(value.contains('@')){
      _email = value;
    }
    else{
      print('이메일 형식이 아닙니다.');
    }
  }

  @override
  String toString() {
    return 'User{_name: $_name, _birth: $_birth, _age: $_age}';
  }
}




void main(){

  //객체생성
  Person person1 = Person();
  person1.name = '김유신';
  person1.age = 23;

  person1.introduce();

  //객체생성(Cascade 연산자 초기화), 연쇄적으로 되는거?
  Person person2 = Person()
  ..name = '김춘추'
  ..age =21
  ..introduce();

  //User 객체 생성
  var user1 = User('홍길동', '1990-09-02');
  user1.initEmail('hong@gmail.com');//late속성을 초기화
  user1.hello();

  //속성 참조
  print('이름 : ${user1._name}'); // _name 직접접근안됨,Dart에서 _(언더스코어)는 “파일 단위(private to library)”이라 지금은 됨
  print('나이 : ${user1.age}'); //_age직접접근 안됨, age getter호출

  //Setter사용
  user1.age=30;
  print('나이 : ${user1.age}'); //_age직접접근 안됨, age getter호출
  print(user1);
  
  var user2 = User.withAge('김유신', '1999-02-03', 23);
  user2.initEmail('kim@naver.com');
  user2.hello();

  var user3 = User.guest('김춘추');
  user3.initEmail('chun@naver.com');
  user3.hello();

  var user4 = User.withAge('장보고', '1999-02-03', 23);
  user2.initEmail('kim@naver.com');
  user2.hello();

  //클래스속성
  print('전체인원 :  ${User.total}');
}
