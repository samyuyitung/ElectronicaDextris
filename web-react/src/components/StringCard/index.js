import React from 'react'
import Card from '@material-ui/core/Card'
import CardHeader from '@material-ui/core/CardHeader';
import IconButton from '@material-ui/core/IconButton';
// icons
import MoreVertIcon from '@material-ui/icons/MoreVert';

import SwitchListSecondary from "../List/List.js";

const StringCard = ({string}) =>
    <div>
        <Card>
            <CardHeader
                action={
                <IconButton>
                    <MoreVertIcon />
                </IconButton>
                }
                title="Melody Strings"
            />
            <SwitchListSecondary>
            </SwitchListSecondary>
        </Card>
    </div>

export default StringCard