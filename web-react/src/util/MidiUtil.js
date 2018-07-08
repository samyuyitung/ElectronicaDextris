
export default {
    rescaleToMidi:(min, max, val) => {
        return (val / (max - min) * 127)
    }
}