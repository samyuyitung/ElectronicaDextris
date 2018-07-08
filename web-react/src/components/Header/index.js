import React from 'react';

import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import Tabs from '@material-ui/core/Tabs';
import Tab from '@material-ui/core/Tab';


const header = () => 
<AppBar position="fixed" color="secondary">
  <Toolbar>
    <Typography variant="title" color="inherit" className="flex">
      Electronica Dextris
    </Typography>
    <Tabs>
      <Tab label="Basic" />
      <Tab label="Advanced" />
      <Tab label="Performance"/>
    </Tabs>
  </Toolbar>
</AppBar>

export default header;