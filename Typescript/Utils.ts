import moment from 'moment';
let utilities = {
    capitalize: (text: string): string => (text[0]?.toUpperCase() || '') + text.slice(1),
    updateItemList: <T extends Record<string, any>>(list: Array<T>, item: T, action: 'ADD' | 'DELETE' | 'UPDATE' | 'PUT', key: keyof T = 'id'): typeof list => {
        list = list || [];
        let newList = list.slice();
        let itemIndex;
        if (action === 'UPDATE') {
            newList = newList.map((x => x[key] === item[key] ? item : x));
            // itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            // if (itemIndex !== -1)
            //     newList.splice(itemIndex, 1, item);
            return newList;
        } else if (action === 'ADD') {
            newList.unshift(item);
            return newList;
        } else if (action === 'DELETE') {
            return newList.filter(listItem => item[key] !== listItem[key]);
        }
        else if (action === 'PUT') {
            itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            if (itemIndex !== -1)
                newList.splice(itemIndex, 1, item);
            else {
                newList.push(item);
            }
            return newList;
        }
        return newList;
    },
    jsonParser: (data: any, keys: Array<string>) => {
        let updatedObject: any
        if (Array.isArray(data)) {
            updatedObject = [...data];
            updatedObject.forEach((objItem: any) => {
                for (let i = 0; i < keys.length; i++) {
                    try {
                        if (typeof objItem[keys[i]] === 'string') objItem[keys[i]] = JSON.parse(objItem[keys[i]])
                        else continue;
                    } catch (e) { objItem[keys[i]] = {} }
                }
            });
        }
        else {
            updatedObject = { ...data };
            for (let i = 0; i < keys.length; i++) {
                try {
                    if (typeof data[keys[i]] === 'string') updatedObject[keys[i]] = JSON.parse(data[keys[i]]);
                    else continue;
                } catch (e) { updatedObject[keys[i]] = {} }
            }
        }
        return updatedObject;
    },
    validateEmail: (email: string) => {
        let tester = /^[-!#$%&'*+\/0-9=?A-Z^_a-z{|}~](\.?[-!#$%&'*+\/0-9=?A-Z^_a-z`{|}~])*@[a-zA-Z0-9](-*\.?[a-zA-Z0-9])*\.[a-zA-Z](-?[a-zA-Z0-9])+$/;
        if (!email)
            return false;

        if (email.length > 254)
            return false;

        var valid = tester.test(email);
        if (!valid)
            return false;

        // Further checking of some things regex can't handle
        var parts = email.split("@");
        if (parts[0].length > 64)
            return false;

        var domainParts = parts[1].split(".");
        if (domainParts.some(function (part) { return part.length > 63; }))
            return false;

        return true
    },
    validateUrl: (uri: string): boolean => {
        let tester = /^(?:http(s)?:\/\/)?[\w.-]+(?:\.[\w\.-]+)+[\w\-\._~:/?#[\]@!\$&'\(\)\*\+,;=.]+$/;
        if (!uri) return false;
        return tester.test(uri);
    },
    getUrl: (text: string): string | null => {
        let tester = /(https?:\/\/[^\s]+)/;
        const a = text.match(tester);
        return a && a[0];
    },
    findValues: (superSet: Array<any>, subSet: string | Array<string>, findKey: string = 'name', mapKey: string = 'value', isReturnItem: boolean = false): Array<string> => {
        if (typeof subSet === 'string')
            subSet = [subSet];
        let filteredValues = (superSet || []).filter(item => (subSet || []).indexOf(item[mapKey]) !== -1);
        if (isReturnItem)
            return filteredValues;
        return (filteredValues || []).map(item => item[findKey]);
    },
    timeFromNow: (date: string): string => {
        const min = moment().diff(moment(date), 'minutes');
        const hour = moment().diff(moment(date), 'hours');
        const days = moment().diff(moment(date), 'days');
        const weeks = moment().diff(moment(date), 'weeks');
        const months = moment().diff(moment(date), 'months');
        return min < 60 ? (min === 0 ? 'now' : `${min}m`) : (hour < 24 ? `${hour}h` : (days < 7 ? `${days}d` : (weeks < 4 ? `${weeks}w` : `${months}mo`)));
    },
    toggleItemFromList: (list: any[] = [], item: any, key: string = 'id', comparisonFunction?: (currentItem: any, item: any) => boolean) => {
        let updatedList: any[] = [...list];
        let index = list.findIndex(i => comparisonFunction ? comparisonFunction(i, item) : i[key] === item[key]);
        index === -1 ? updatedList.push(item) : updatedList.splice(index, 1);
        return updatedList;
    },

}

export default utilities;
