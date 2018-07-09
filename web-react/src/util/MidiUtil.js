
export default {
    rescaleToMidi:(min, max, val) => {
        return ((val - min) / (max - min) * 127)
    }
}
