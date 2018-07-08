import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Slider from '@material-ui/lab/Slider';


import MidiController from '../../Controllers/MidiController';
import { VOLUME_CC } from '../../Constants/MidiConstants';
import MidiUtil from '../../util/MidiUtil.js'
const styles = {
  root: {
    width: 180,
  },
};

class SimpleSlider extends React.Component {


  constructor(props) {
    super(props)
    this.state = {
    value: 50,
    note: props.note
  }
  };


  handleChange = (event, value) => {
    this.setState({ value });
    this.handleMidi(value);
  };

  handleMidi = (value) => {
    const midiVal = MidiUtil.rescaleToMidi(0,100, value);
    MidiController.sendCC(VOLUME_CC, midiVal, this.state.note.channel);
  }

  render() {
    const { classes } = this.props;
    const { value } = this.state;

    return (
      <div className={classes.root}>
        <Slider value={value} aria-labelledby="label" onChange={this.handleChange.bind(this)} />
      </div>
    );
  }
}

SimpleSlider.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(SimpleSlider);