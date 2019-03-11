import React, { Component, Fragment} from 'react';

class App extends Component {

  constructor(props){
    super(props);
    this.state = {
      state: "stop",
      timeNow: 0,
      timeTotal: 0,
      timeArray: [],
      interval: null,
      type: {"start": "start", "stop": "stop"}
    }

    this.start = this.start.bind(this);
    this.record = this.record.bind(this);
    this.reset = this.reset.bind(this);
    this.renderTime = this.renderTime.bind(this);
    this.clickOne = this.clickOne.bind(this);
    this.clickTwo = this.clickTwo.bind(this);

  }
  
  start(e){
      e.target.innerHTML = this.state.type.stop;
      let interval = setInterval(() => {
        let timeNow = this.state.timeNow;
        let timeTotal = this.state.timeTotal;
        timeNow++;
        timeTotal++;
        this.setState({
          state: "start",
          timeNow: timeNow,
          timeTotal: timeTotal,
          interval: interval
        })
      }, 100);
  }


  stop(e){
      e.target.innerHTML = this.state.type.start;
      clearInterval(this.state.interval);
      this.setState({
        state: "stop"
      })
  }
  

  record(){
    const timeNow = this.state.timeNow;
    let timeTotal = this.state.timeTotal;
    this.setState({
      timeNow: 0,
      timeTotal: timeTotal,
      timeArray: [...this.state.timeArray, timeNow],
      interval: this.state.interval
    })
    console.log(this.state);
  }
  

  reset(e){
    this.setState({
      timeNow: 0,
      timeTotal: 0,
      timeArray: [],
    })
  }
  

  renderTime(n){
    let m = Math.floor(n / 10 / 60);
    let s = Math.floor(n / 10 % 60);
    let ss = n % 10;    
    return m + ":" + s + "." + ss;
  }
  

  clickOne(e){
    const btn = e.target.nextSibling;
    if(this.state.state === this.state.type.stop){
      this.start(e);
      
      btn.innerHTML = "record";
    }else if(this.state.state === this.state.type.start){
      this.stop(e);
      btn.innerHTML = "reset";
    }

  }
  
  clickTwo(e){
    if(this.state.state === this.state.type.stop){
      this.reset();
    }else if(this.state.state === this.state.type.start){
      this.record();
    }
  }


  componentDidMount(){

  }

  
  render() {
    return (
      <Fragment>
        <div>总计时间{this.renderTime(this.state.timeTotal)}</div>
        <div>本轮时间{this.renderTime(this.state.timeNow)}</div>
        <button onClick={this.clickOne}>start</button>
        <button onClick={this.clickTwo}>reset</button>
        {
          this.state.timeArray.map((item, index) => {
            return <div key={index}>计次{index + 1}    {this.renderTime(item)}</div>
          })
        }
      </Fragment>
    );
  }
}

export default App;
