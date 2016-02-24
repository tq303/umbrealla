import React from 'react';
import ColorPicker from 'react-color';

import Light from './Light';

class Lights extends React.Component {

    constructor( params ) {
        super( params );

        // assign <Light/> to this.lights array
        let lights = [];

        for (let i = 0; i < window.STRIP_COUNT; i++) {
            lights[i] = null;
        }

        this.state = {
            lights: lights,
            integerColour: 0
        };
    }

    activateAll() {
        this.setState(( state )=> {
            return {
                lights: state.lights.map(()=> this.state.integerColour)
            };
        });
    }

    deActivateAll() {
        this.setState(( state )=> {
            return {
                lights: state.lights.map(()=> null)
            };
        });
    }

    colourChange( colour ) {
        this.setState({ integerColour: `#${colour.hex}` });
    }

    render() {
        return (
            <div id="ui-lights">

                <div className="lights">
                    <p><Light updateColour={ this.state.integerColour } colour={ this.state.lights[0] }/></p>
                    <p><Light updateColour={ this.state.integerColour } colour={ this.state.lights[7] }/><Light updateColour={ this.state.integerColour } colour={ this.state.lights[1] }/></p>
                    <p><Light updateColour={ this.state.integerColour } colour={ this.state.lights[6] }/><Light updateColour={ this.state.integerColour } colour={ this.state.lights[2] }/></p>
                    <p><Light updateColour={ this.state.integerColour } colour={ this.state.lights[5] }/><Light updateColour={ this.state.integerColour } colour={ this.state.lights[3] }/></p>
                    <p><Light updateColour={ this.state.integerColour } colour={ this.state.lights[4] }/></p>
                </div>

                <div className="controls">
                    <button onClick={ this.activateAll.bind(this) }><i className="fa fa-sun-o"></i></button>
                    <button onClick={ this.deActivateAll.bind(this) }><i className="fa fa-circle-thin"></i></button>
                </div>
                <div className="set-colour">
                    <ColorPicker type="slider" color={ this.state.integerColour } onChange={ this.colourChange.bind(this) } />
                </div>

            </div>
        )
    }
}

export default Lights;
