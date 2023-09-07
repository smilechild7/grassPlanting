import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  //
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
          // 알아서 상중하로 나누어주는 위젯
          appBar: AppBar(
            title: const Text('EOS BASIC'),
            centerTitle: true,
            leading: Icon(Icons.dehaze), // 햄버거 아이콘
            actions: [Icon(Icons.settings_outlined)], // 톱니바퀴(설정) 아이콘
          ),
          body: SafeArea(
              // 휴대폰 조건에 따라 화면이 잘리지 않도록 방지
              child: Column(
            // 세로정렬
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Image.asset('assets/eos_logo.png', width: 300, height: 300)
            ],
          ))),
    );
  }
}
