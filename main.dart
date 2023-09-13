import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  //
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
          // 알아서 상중하로 나누어주는 위젯
          appBar: AppBar(
            backgroundColor: Colors.green,
            title: const Text('EOS BASIC'),
            centerTitle: true,
            leading: Icon(Icons.dehaze), // 햄버거 아이콘
            actions: [Icon(Icons.settings_outlined)], // 톱니바퀴(설정) 아이콘
          ),
          floatingActionButton: FloatingActionButton(
            onPressed: () {},
            backgroundColor: Colors.green,
            child: Icon(Icons.add),
          ),
          body: SafeArea(
              // 휴대폰 조건에 따라 화면이 잘리지 않도록 방지
              child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 20),
            child: Column(
              // 세로정렬
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Image.asset('assets/eos_logo.png', width: 200, height: 200),
                Container(
                  height: 50,
                ),
                Text(
                  "00:00:00",
                  style: TextStyle(
                    fontSize: 35,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                Container(
                  height: 50,
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
                Padding(
                  padding:
                      const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Icon(
                        Icons.play_circle,
                        size: 40,
                        color: Colors.green,
                      ),
                      Text(
                        "국어",
                        style: TextStyle(fontSize: 25),
                      ),
                      Text(
                        "00:00:00",
                        style: TextStyle(fontSize: 25),
                      ),
                    ],
                  ),
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
                Padding(
                  padding:
                      const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Icon(
                        Icons.play_circle,
                        size: 40,
                        color: Colors.green,
                      ),
                      Text(
                        "수학",
                        style: TextStyle(fontSize: 25),
                      ),
                      Text(
                        "00:00:00",
                        style: TextStyle(fontSize: 25),
                      ),
                    ],
                  ),
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
              ],
            ),
          ))),
    );
  }
}
