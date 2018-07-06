import React from 'react';
import './App.css';
// @material-ui/core
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import Tabs from '@material-ui/core/Tabs';
import Tab from '@material-ui/core/Tab';
import Grid from "@material-ui/core/Grid";
// core components
import GridItem from "./components/Grid/GridItem.js";
import {StringCard} from './components';

import 'typeface-roboto'

function App() {
  return (
      <html>
        <body>
          <AppBar position="fixed" color="primary">
            <Toolbar>
              <Typography variant="title" color="inherit" className="flex">
                Electronica Dextris
              </Typography>
              <Tabs>
                <Tab label="Basic" />
                <Tab label="Advanced" />
                <Tab label="Performance" href="#basic-tabs" />
              </Tabs>
            </Toolbar>
          </AppBar>
          <div className="container">
           <Grid container>
              <GridItem xs={12} sm={6} md={3}>
                <StringCard/>
              </GridItem>
              <GridItem xs={12} sm={6} md={3}>
                <StringCard/>
              </GridItem>
              <GridItem xs={12} sm={6} md={3}>
                <StringCard/>
              </GridItem>
            </Grid>
          </div>
        </body>
      </html>
  );
}

export default App;
