import React from 'react';
import './App.css';
// @material-ui/core
import Grid from "@material-ui/core/Grid";
// core components
import GridItem from "./components/Grid/GridItem.js";
import {StringCard} from './components';
import Header from './components/Header';
import 'typeface-roboto';


class App extends React.Component {

  constructor(props) {
    super(props);

    this.state = {
      currentPane: 'Basic'
    }

  }


  render(){
    switch(this.state.currentPane.toLowerCase()) {
      case 'basic': return this.renderBasic();
      default: return <div/>
    }
  }

  renderBasic() {

    return (
      <div>
            <Header/>
            <div className="container">
            <h1>{this.state.currentPane}</h1>
            <Grid container>
                <GridItem xs={12} sm={6} md={3}>
                  <StringCard stringType="Melody" keys={[{note: "A4", channel: 1}, {note: "B5", channel:2} ]}/>
                </GridItem>
                <GridItem xs={12} sm={6} md={3}>
                  <StringCard  stringType="Drone" keys={[{note: "A4", channel: 3}, {note: "B5", channel:4}]}/>
                </GridItem>
                <GridItem xs={12} sm={6} md={3}>
                  <StringCard stringType="Sympathetic" keys={[{note: "A4", channel: 5}, {note: "B5", channel:6}] }/>
                </GridItem>
              </Grid>
            </div>
      </div>
    );
  }
}

export default App;