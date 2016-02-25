import React from 'react';
import ReactDOM   from 'react-dom';

import UIAnimation from './UIAnimation';

class Animator {

    constructor( umbrellas ) {

        this.frames    = [];
        this.umbrellas = umbrellas;

        ReactDOM.render(<UIAnimation frames={ this.frames } updateParent={ this.update.bind(this) } />, document.getElementById('ui-animation'));
    }

    update( frames ) {
        console.log( frames )
    }

}

export default Animator;
