import React from 'react'
import Card from '@material-ui/core/Card'
import CardHeader from '@material-ui/core/CardHeader';
import Button from '@material-ui/core/Button';

import SwitchListSecondary from "../List/List.js";
import header from '../Header/index.js';

const headerStyle = {
    backgroundColor: '#2F80ED',
    color: 'white!important',
    height: '20px'

  };
  
const StringCard = (props) =>
    <div>
        <Card>
            <CardHeader
                action={
                <Button size='small' type='text' style={{color:'white', padding: '5px', height: '10px'}}>
                    edit
                </Button>
                }
                subheader={`${props.stringType} Strings`}
                style={headerStyle}
            />
            <SwitchListSecondary keys={props.keys}/>
        </Card>
    </div>

export default StringCard