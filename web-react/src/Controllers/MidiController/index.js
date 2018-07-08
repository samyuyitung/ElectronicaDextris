import Midi from 'webmidi';

let output = null;

const enable = () => {
    if (Midi.enabled) {
        return true;
    } else {
        return Midi.enable((e) => { 
            if(e || Midi.outputs.length === 0) return false;
            output = Midi.outputs[0];
            return true
        });
    }
};
export default {

    sendCC: (id, value, channel) => {
        if (enable()) {
            output.sendControlChange(id, value, channel ? channel : 'all');
        }
    },

    sendNoteOn: (note, velocity, channel) => {
        if (enable()) {
            output.sendNoteOn(note, velocity, channel ? channel : 'all');
        }
    }

}
