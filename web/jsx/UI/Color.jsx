import React from 'react';
import Processing from 'processing-js';

require('../../styles/ui.scss');

class UI extends React.Component {
    constructor() {
        super();
        this.state = {
            cycle: 0
        }
    }
    nextCycle() {
        this.setState({
            cycle: this.state.cycle++
        });
    }
    render() {
        return (
            <div>
                <input type='text' onChange={ this.update.bind(this) } />
                <h1>{this.state.title}</h1>
            </div>
        )
    }
}

/*
UI.propTypes = {
    title: React.PropTypes.string,
    tab:   React.PropTypes.number.isRequired
}

UI.defaultProps = {
    title: 'UI'
}
*/
export default UI;
