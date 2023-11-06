import 'package:eos_practice/timer_item.dart'; // Import your TimerItem class
import 'package:flutter/material.dart';
import 'dart:async';

void main() {
  runApp(ClassApp());
}

class ClassApp extends StatefulWidget {
  const ClassApp({Key? key}) : super(key: key);

  @override
  State<ClassApp> createState() => _ClassAppState();
}

class _ClassAppState extends State<ClassApp> {
  var _time = 0;
  var _totalTime = 0;
  var _isRunning = false;
  var _timer;
  List<TimerItem> timerItems = [];

  @override
  void initState() {
    super.initState();
    _timer = Timer.periodic(Duration(seconds: 1), _updateTimer);
  }

  void _updateTimer(Timer timer) {
    setState(() {
      if (_isRunning) {
        timerItems.forEach((element) {
          if (element.isRunning) element.time++;
        });
        _totalTime++;
      }
    });
  }

  void _startTimer(index) {
    setState(() {
      _isRunning = true;
      timerItems[index].isRunning = true;
    });
  }

  void _pauseTimer(index) {
    setState(() {
      timerItems[index].isRunning = false;
      if (!timerItems.any((element) => element.isRunning)) _isRunning = false;
    });
  }

  void _resetTimer() {
    setState(() {
      _isRunning = false;
      _totalTime = 0;
      timerItems.forEach((element) {
        element.time = 0;
        element.isRunning = false;
      });
    });
  }

  void addItem() {
    timerItems.add(TimerItem()); // Make sure TimerItem class is defined
  }

  @override
  Widget build(BuildContext context) {
    var totalSec = (_totalTime % 60).toString().padLeft(2, '0');
    var totalMin = ((_totalTime ~/ 60) % 60).toString().padLeft(2, '0');
    var totalHour = (_totalTime ~/ 3600).toString().padLeft(2, '0');

    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('EOS BASIC'),
          centerTitle: true,
          backgroundColor: Colors.green,
          leading: Icon(Icons.dehaze),
          actions: [Icon(Icons.settings_outlined)],
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: addItem,
          child: Icon(Icons.add),
          backgroundColor: Colors.green,
        ),
        body: SafeArea(
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 20),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                InkWell(
                  onTap: _resetTimer,
                  child: Image.asset(
                    'assets/eos_logo.png',
                    width: 150,
                    height: 150,
                  ),
                ),
                Text(
                  "$totalHour:$totalMin:$totalSec",
                  style: TextStyle(fontSize: 35, fontWeight: FontWeight.bold),
                ),
                Container(
                  height: 100,
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
                Expanded(
                  child: ListView.builder(
                    itemCount: timerItems.length,
                    itemBuilder: (context, index) {
                      var sec = (timerItems[index].time % 60)
                          .toString()
                          .padLeft(2, '0');
                      var min = ((timerItems[index].time ~/ 60) % 60)
                          .toString()
                          .padLeft(2, '0');
                      var hour = (timerItems[index].time ~/ 3600)
                          .toString()
                          .padLeft(2, '0');

                      return Column(
                        children: [
                          Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 16, vertical: 12),
                            child: Row(
                              mainAxisAlignment: MainAxisAlignment.spaceBetween,
                              children: [
                                IconButton(
                                  padding: EdgeInsets.all(0),
                                  onPressed: () {
                                    timerItems[index].isRunning
                                        ? _pauseTimer(index)
                                        : _startTimer(index);
                                  },
                                  icon: timerItems[index].isRunning
                                      ? Icon(
                                          Icons.pause_circle,
                                          size: 40,
                                          color: Colors.green,
                                        )
                                      : Icon(
                                          Icons.play_circle,
                                          size: 40,
                                          color: Colors.green,
                                        ),
                                ),
                                Text(
                                  timerItems[index].name,
                                  style: TextStyle(fontSize: 25),
                                ),
                                Text(
                                  "$hour:$min:$sec",
                                  style: TextStyle(fontSize: 25),
                                )
                              ],
                            ),
                          ),
                          Divider(
                            height: 3,
                            color: Colors.black,
                          ),
                        ],
                      );
                    },
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
