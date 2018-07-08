import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import List from '@material-ui/core/List';
import ListItem from '@material-ui/core/ListItem';
import ListItemIcon from '@material-ui/core/ListItemIcon';
import Avatar from '@material-ui/core/Avatar';
// core

import SimpleSlider from "../Slider/Slider.js";

const classes = {
  root: {
    width: '100%',
    maxWidth: 360,
  },
  avatar: {
    margin: 10,
  },
};

class SwitchListSecondary extends React.Component {

  constructor(props) {
    super(props)
    this.state = {
      keys: props.keys,
      type: props.type
    }
  }

  render() {
    return (
      <div style={{minHeight: '300px'}}>
        <List>
          {this.state.keys.map((note, i) => { 
            return (
               <ListItem key={i}>
                <ListItemIcon key={i}>
                  <Avatar className={classes.avatar} key={i}>{note.note}</Avatar>
                </ListItemIcon>
                <SimpleSlider note={note}/>
              </ListItem>
            )
            })}
        </List>
      </div>
    );
  }
}

export default withStyles(classes)(SwitchListSecondary);