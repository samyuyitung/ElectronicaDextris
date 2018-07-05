import React, { Component } from 'react';
import WebMidi from 'webmidi';


class App extends Component {

  constructor(props) {
    super(props);
    this.state = {
      output: {name: 'none'},
      muted: false
    };
    const self = this;
    WebMidi.enable(() => {console.log(WebMidi.outputs[0]); self.setState({output: WebMidi.outputs[0]})});
  }
  
  render() {
    return (
      <div>
        <h1> Electronica Dextris! </h1>
        <p> Conencted to: { this.state.output.name} </p>
      
        <button onClick={this.handleMute.bind(this)}> {this.state.muted ? 'Unmute' : 'Mute'} </button> 
      </div>
    );
  }

  handleMute() {

    this.state.output.sendControlChange(7, this.state.muted ? 0 : 127, 'all')
    this.setState({muted: !this.state.muted})
  }
}

export default App;
